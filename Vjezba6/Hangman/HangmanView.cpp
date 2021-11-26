#include "HangmanView.h"

void HangmanView::displayHangman() {
	
	if (!ctrl.checkLetter())
	{
		cout << this->drawingTemplates[ctrl.getLives()];
	}
}

void HangmanView::displayCurrentStatus() {

	cout << "\nGAME STATUS     " << ctrl.getCurrentStatus() << endl;
}

void HangmanView::displayAllGuesses() {

	cout << "\n\nAll your guesses: " << ctrl.getAllGuesses() << endl;
}

void HangmanView::displayLivesLeft() {

	if (ctrl.isGameOver()) {
		cout << "\n\nGAME OVER. YOU LOSE!" << endl;
		exit(0);
	}
	 else if (ctrl.isGameWon()) {
		cout << "\n\nGG. YOU WIN" << endl;
		exit(0);
	}
	 else {
		if (ctrl.checkLetter()) {
			cout << "\nYou still have " << ctrl.getLives() << " lives." << endl;
		}
		else {
			cout << "\nYou have " << ctrl.getLives() << " lives remaining. Use them well." << endl;
		}
	}
}

void HangmanView::drawings() {

	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/     0\n   |     /|\\\n   |      |\n   |     / \\\n   |\n___|____\n");		/*right leg*/
	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/     0\n   |     /|\\\n   |      |\n   |     /\n   |\n___|____\n");			/*left leg*/
	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/     0\n   |     /|\\\n   |      |\n   |\n   |\n___|____\n");                /*lower body*/
	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/     0\n   |     /|\\\n   | \n   | \n   | \n___|____\n");					/*right arm*/
	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/     0\n   |     /|\n   |\n   |\n   |\n___|____\n");						    /*torso*/
	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/     0\n   |     /\n   |\n   |\n   |\n___|____\n");							/*left arm*/
	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/     0\n   |\n   |\n   |\n   |\n___|____\n");								/*head*/
	this->drawingTemplates.push_back("\n    _______\n   | /    |\n   |/  \n   | \n   | \n   | \n   | \n___|____\n");								/*setup*/
	
}

void HangmanView::start() {

	ctrl.initialize();
	displayHangman();
	displayCurrentStatus();
	while (1) {

		ctrl.userEntry();
		displayHangman();
		displayCurrentStatus();
		displayAllGuesses();
		displayLivesLeft();

	}

}