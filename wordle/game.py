
import pygame
import time
from random import randint
from case import Case

class Game:
	def __init__(self, screen_size, dico):
		self.screen_size = screen_size
		self.start_timer = time.time()
		self.end_timer = time.time()

		self.background = pygame.image.load("assets/background.jpg")
		self.case_white_image = pygame.image.load("assets/case_white.png")
		self.case_yellow_image = pygame.image.load("assets/case_yellow.png")
		self.case_green_image = pygame.image.load("assets/case_green.png")
		self.case_grey_image = pygame.image.load("assets/case_grey.png")
		self.button_retry = pygame.image.load("assets/button_retry.png")
		self.button_retry_rect = self.button_retry.get_rect()
		self.button_retry_rect.x = (self.screen_size[0] - self.button_retry.get_width()) // 2
		self.button_retry_rect.y = 600
		self.background = pygame.transform.scale(self.background, self.screen_size)

		self.words = dico
		self.word_to_find = self.give_me_one_word()
		self.user_input = []
		self.NB_LETTERS = len(self.word_to_find)
		self.ALPHABET_MIN = "abcdefghijklmnopqrstuvwxyz"
		self.ALPHABET_MAJ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		self.numbers_to_letters = {1 : "one", 2 : "two", 3 : "three", 4 : "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine", 10: "ten"}
		self.CASE_SIZE = 65
		self.DECALAGE = 4
		self.current_word = 0
		self.font = pygame.font.Font(None, 70)
		self.err_font = pygame.font.Font(None, 33)
		self.timer_font = pygame.font.Font(None, 33)
		self.minutes = self.set_timer((self.end_timer - self.start_timer) // 60)
		self.secondes = self.set_timer((self.end_timer - self.start_timer) // 1)
		self.timer_render = self.timer_font.render(f"{self.minutes}:{self.secondes}", True, (30, 30, 30))
		self.sentence = ""
		self.sentence_render = self.err_font.render(self.sentence, True, (235, 239, 246))
		self.sentence_render_size = self.sentence_render.get_size()
		self.grid = [[Case(self.case_white_image,
						(((self.screen_size[0] - self.CASE_SIZE * self.NB_LETTERS - self.DECALAGE * (self.NB_LETTERS - 1))) / 2 + (j * self.CASE_SIZE) + ((j - 1) * self.DECALAGE),
							100 + (i * self.CASE_SIZE) + ((i - 1) * self.DECALAGE)), self) for j in range(self.NB_LETTERS)] for i in range(6)]

	def update(self, screen):
		'''
		update element image of the program
		screen : the window
		'''
		screen.blit(self.background, (0, 0))
		self.display_grid(screen)
		self.display_user_input(screen)
		self.display_sentence(screen)
		self.display_timer(screen)

	def set_timer(self, unite):
		'''
		set the timer unite to the right format(2 digit)
		unite : the unite to set
		return -> the string created
		'''
		if unite < 10:
			unite = "0" + str(unite)
		else:
			unite = str(unite)
		return (unite)
	
	def display_timer(self, screen):
		'''
		set and display the timer on the screen
		screen: the window
		'''
		self.minutes = self.set_timer(int((self.end_timer - self.start_timer) // 60))
		self.secondes = self.set_timer((int(self.end_timer - self.start_timer) % 60))
		self.timer_render = self.timer_font.render(f"{self.minutes}:{self.secondes}", True, (30, 30, 30))
		self.timer_render_size = self.timer_render.get_size()
		screen.blit(self.timer_render, ((self.screen_size[0] - self.timer_render.get_width()) // 2, 30))

	def display_retry_button(self, screen):
		'''
		display the play again bouton
		'''
		screen.blit(self.button_retry, ((self.screen_size[0] - self.button_retry.get_width()) // 2, 600))

	def error(self, code):
		'''
		display error sentence about the user input
		code : different error code to print an adapted sentence
		'''
		if code == -1:
			self.set_new_sentence(f"You need {self.numbers_to_letters[self.NB_LETTERS]} letters to make a word !")
		elif code == -2:
			self.set_new_sentence("You need a valid word !")
	
	def set_win_message(self):
		'''
		set the self.sentence to the victory phrase
		'''
		sentence = f"Congratulations you won in {str(self.current_word)} tr"
		if (self.current_word > 1):
			sentence += "ies !"
		else:
			sentence += "y !"
		self.set_new_sentence(sentence)

	def set_lose_message(self):
		'''
		set the self.sentence to the defeat phrase
		'''
		word = ""
		for elem in self.word_to_find:
			word += elem[0]
		self.set_new_sentence(f"You lost, the word was {word.lower()}")

	def set_new_sentence(self, text):
			'''
			change the varaible sentence by text; None corresponding to an empty sentence
			'''
			self.sentence = text
			self.sentence_render = self.err_font.render(self.sentence, True, (235, 239, 246))
			self.sentence_render_size = self.sentence_render.get_size()

	def display_sentence(self, screen):
		'''
		display your sentence on the screen
		screen : the window
		'''
		screen.blit(self.sentence_render, ((self.screen_size[0] - self.sentence_render_size[0]) // 2, 100 + 6 * self.CASE_SIZE + 5 * self.DECALAGE + 50))

	def report_good_letters(self, pre_line, new_line):
		'''
		set letters already found to the new_line to display them
		pre_line : previous line
		new_line : new current line
		'''
		for i in range(self.NB_LETTERS):
			self.grid[new_line][i].good_letter = self.grid[pre_line][i].good_letter
			self.grid[new_line][i].set_new_letter(self.grid[new_line][i].good_letter)

	def display_letter(self, case, screen):
		'''
		display letter image of the case on the screen
		case : one case of the grid
		screen : the window
		'''
		if case.letter != None:
			screen.blit(case.letter_render, (case.pos[0] - case.letter_render_size[0] // 2 + 32, case.pos[1] - case.letter_render_size[1] // 2 + 34))
		elif case.good_letter != None and self.user_input == []:
			screen.blit(case.letter_render, (case.pos[0] -  case.letter_render_size[0] // 2 + 32, case.pos[1] -  case.letter_render_size[1] // 2 + 34))


	def compare_input_and_word(self, line):
		'''
		Compare user input and the word to find to set the color of the line. We search first all letters corresponding exactly of the word to find,
		then set a boolean to 0 and mark the letter in green.
		After, we check all letter without a new color and check in the all word to find if this letters appears (skipping the letters with the boolean set on 0) and mark them
		with yellow if the letters is found and with grey if the letters isn't found.
		finally, the report_goo_letters fonction is called.
		line : current user input
		return -> return the number of letters correct 
		'''
		for i in range(len(self.user_input)):
			self.grid[line][i].image = self.case_grey_image
		count = 0
		for i in range(len(self.user_input)):
			if self.word_to_find[i][0] == self.user_input[i]:
				self.grid[line][i].image = self.case_green_image
				self.word_to_find[i][1] = 0
				self.grid[line][i].good_letter = self.user_input[i]
				count += 1

		for i in range(len(self.user_input)):
			if self.word_to_find[i][0] == self.user_input[i]:
				continue
			for j in range(len(self.word_to_find)):
				if self.word_to_find[j][0] == self.user_input[i] and self.word_to_find[j][1] != 0:
					self.grid[line][i].image = self.case_yellow_image
					self.word_to_find[j][1] = 0
					break
	
		self.current_word += 1
		self.user_input = []
		for i in range(len(self.word_to_find)):
			self.word_to_find[i][1] = 1
		if (count != self.NB_LETTERS and line < 5):
			self.report_good_letters(line, line + 1)
		return(count)

	def display_user_input(self, screen):
		'''
		call the display letter fonction for all case of the grid
		screen : the window
		'''
		for element in self.grid:
			for case in element:
				self.display_letter(case, screen)

	def	display_grid(self, screen):
		'''
		display the image of all case in the grid
		screen : the window
		'''
		for element in self.grid:
			for value in element:
				screen.blit(value.image, value.pos)

	def give_me_one_word(self):
		'''
		Choose a random word in the dictionary
		return -> a list of list containing each letter of the word in MAJ and a boolean 
		'''
		word = self.words[randint(0, len(self.words) - 1)]
		#print(word)
		tword = [[elem.upper(), 1] for elem in word]
		return (tword)

	def str_compare(self, word, input_user):
		'''
		Compare two string of characters
		word : the word to compare
		input_user : the input user word
		return -> 0 if the strings ar the same, a positive number if word > input_user, a negative number if user_input > word 
		'''
		for i in range(len(word)):
			if word[i] != input_user[i]:
				return (ord(word[i]) - ord(input_user[i]))
		return (0)

	def check_user_input(self):
		'''
		Check if the word is valid and if the word is in the wordlist with a binairy search
		return -> a code error, -1 if the word is to short, -2 if the word isn't in the dictionary, 0 if everything is all right
		'''
		if len(self.user_input) != self.NB_LETTERS:
			return (-1)
		start = 0
		end = len(self.words) - 1
		while start <= end:
			compare = self.str_compare(self.words[(start + end) // 2].upper(), self.user_input)
			if compare == 0:
				return (0)
			if compare < 0:
				start = (start + end) // 2 + 1
			else:
				end = (start + end) // 2 - 1
		return (-2)

	def reset(self):
		'''
		reset all variable which need to be reset to play again
		'''
		self.word_to_find = self.give_me_one_word()
		self.start_timer = time.time()
		self.user_input = []
		self.NB_LETTERS = len(self.word_to_find)
		self.current_word = 0
		self.sentence = ""
		self.sentence_render = self.err_font.render(self.sentence, True, (235, 239, 246))
		self.sentence_render_size = self.sentence_render.get_size()
		self.grid = [[Case(self.case_white_image,
						(((self.screen_size[0] - self.CASE_SIZE * self.NB_LETTERS - self.DECALAGE * (self.NB_LETTERS - 1))) / 2 + (j * self.CASE_SIZE) + ((j - 1) * self.DECALAGE),
							100 + (i * self.CASE_SIZE) + ((i - 1) * self.DECALAGE)), self) for j in range(self.NB_LETTERS)] for i in range(6)]
