
import pygame

class Case:
	def __init__(self, image, pos, game, letter=None):
		self.game = game
		self.image = image
		self.image = pygame.transform.scale(self.image, (game.CASE_SIZE, game.CASE_SIZE))
		self.pos = pos
		self.letter = letter
		self.letter_render = self.game.font.render(self.letter, True, (235, 239, 246))
		self.letter_render_size = self.letter_render.get_size()
		self.good_letter = letter

	def set_new_letter(self, letter):
		'''
		change the letter image to the the new letter
		letter: the new letter
		'''
		self.letter = letter
		if self.letter == None and self.good_letter != None:
			self.letter_render = self.game.font.render(self.good_letter, True, (235, 239, 246))
		else:
			self.letter_render = self.game.font.render(self.letter, True, (235, 239, 246))
		self.letter_render_size = self.letter_render.get_size()
