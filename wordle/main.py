
import pygame
import os
import time
from random import randint
from sys import argv
from game import Game

def dico_error(code, line=None):
	'''
	Print a different message depending on the error
	code : the code of the error
	line : the line where the error has been seen
	'''
	if code == -1:
		print("Permission Denied")
	elif code == -2:
		print("Your dictionary is empty")
	elif code == -3:
		print(f"Your dictionary contains invalid letter at line : {line}")
	elif code == -4:
		print(f"Your dictionary contains words of different size at line : {line}")

def check_parse(words):
	'''
	check the length and characters of the words in the dictionary and return a code error if an error appears 
	words : a list of words 
	return -> -3 bad character, -4 bad legth, 0 all right
	'''
	i = 1
	lenght = len(words[0])
	for element in words:
		for char in element:
			if not char in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
				return (i, -3)
			if len(element) != lenght:
				return (i, -4)
		i += 1
	return (-1, 0)

def parse_txt(path):
	'''
	parse a file  to put each words in a list(tab)
	path : the path to the file
	return -> 
	'''
	open_try = os.access(path, os.R_OK)
	if not open_try:
		return (None, -1, None)
	file = open(path, "r")
	tab = [x.strip().upper() for x in file.readlines()]
	if len(tab) <= 0:
		return (None, -2, None)
	line = check_parse(tab)
	if line[0] != -1:
		return (None, line[1], line[0])
	file.close()
	tab.sort()
	return (tab)

def choice_dico():
	'''
	return -> 	return one of the path put in the arguments, if one of the path is incorrect,
				nothing append until this path isn't choose
	'''
	if len(argv) == 2:
		dico_path = argv[1]
	elif (len(argv) > 2):
		dico_path = argv[randint(1, len(argv) - 1)]
	else:
		dico_path = "files/words.txt"
	return (dico_path)

def play_again(game):
	'''
	Reset all to clean the game and play again
	game : the game object
	'''
	if len(argv) != 1 and len(argv) != 2:
		game.words = parse_txt(choice_dico())
	if game.words[0] == None:
		print("The dictionary is invalid : ", end="")
		dico_error(game.words[1], game.words[2])
		exit()
	game.reset()

words = parse_txt(choice_dico())

if words[0] == None:
	print("The dictionary is invalid : ", end="")
	dico_error(words[1], words[2])
	exit()

#set up my window
pygame.init()

pygame.display.set_caption("Wordle")
screen_size = 580, 700

icon = pygame.image.load("assets/wordle_icon.png")
screen = pygame.display.set_mode(screen_size)
pygame.display.set_icon(icon)

running = True
playing = True

#for one strange bug
refresh = 1
win = 0

#init the game object
game = Game(screen_size, words)

#loop of the game
while running:
	#win and lose conditions
	if win == game.NB_LETTERS:
		game.set_win_message()
		playing = False
	elif game.current_word > 5:
		game.set_lose_message()
		playing = False
	if playing:
		game.end_timer = time.time()

	#update the screen
	game.update(screen)

	if not playing:
		game.display_retry_button(screen)

	#set up new screen
	pygame.display.flip()

	#management of all user event
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
			pygame.quit()

		elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE and refresh <= 0:
			running = False
			pygame.quit()

		elif event.type == pygame.KEYDOWN and not playing and event.key == pygame.K_SPACE and refresh <= 0:
			play_again(game)
			refresh = 1
			playing = True
			win = 0
		elif event.type == pygame.MOUSEBUTTONDOWN and not playing:
			if game.button_retry_rect.collidepoint(event.pos):
				play_again(game)
				refresh = 1
				playing = True
				win = 0
				
		if event.type == pygame.KEYDOWN and playing and refresh <= 0:
			if event.key == pygame.K_BACKSPACE:
				game.set_new_sentence(None)
				if (len(game.user_input) > 0):
					game.grid[game.current_word][len(game.user_input) - 1].set_new_letter(None)
					del game.user_input[-1]
			elif event.key == pygame.K_RETURN:
				err_code = game.check_user_input()
				if err_code == 0:
					win = game.compare_input_and_word(game.current_word)
					game.set_new_sentence(None)
				else:
					game.error(err_code)
			elif event.key >= pygame.K_a and event.key <= pygame.K_z:
				if len(game.user_input) < game.NB_LETTERS:
					if game.user_input == []:
						for i in range(game.NB_LETTERS):
							game.grid[game.current_word][i].set_new_letter(None)
					game.user_input.append(game.ALPHABET_MAJ[event.key - 97])
					game.grid[game.current_word][len(game.user_input) - 1].set_new_letter(game.ALPHABET_MAJ[event.key - 97])
	refresh -= 1

