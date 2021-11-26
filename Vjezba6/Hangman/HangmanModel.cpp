#include "HangmanModel.h"
#include <time.h>
#include <random>
#include <fstream>
#include <cctype>

using namespace std;

void HangmanModel::randomMovie() {
	srand(time(NULL));
	/*string randMovie;*/
	ifstream movies("movie.txt");
	unsigned int i = 0;
	if (movies.is_open()) {
		while (getline(movies, this->randMovie))
		{
			/*cout << randMovie << endl;*/
			i++;
		}
	}
	int n = 1 + rand() % i;
	/*cout <<"n = " << n << endl;*/
	movies.clear();
	movies.seekg(0);
	for (int i = 0; i < n; i++)
		getline(movies, this->randMovie);
	/*randMovie.clear();*/
	/*getline(movies, randMovie);*/
	transform(randMovie.begin(), randMovie.end(), randMovie.begin(),[](unsigned char c) { return tolower(c); });
	cout <<"*SPOILER ALERT* The chosen one is " <<"'" << this->randMovie <<"'" << endl;
	movies.close();
}

void HangmanModel::incognito(){
	int len = this->randMovie.size();
	for (int i = 0; i < len; i++)
		if (isalnum(this->randMovie[i])){
			currentStatus.push_back('_');
			currentStatus.push_back(' ');
		}
		else {
			currentStatus.push_back(randMovie[i]);
			currentStatus.push_back(' ');
		}
			
	//cout << this->currentStatus << endl;
}

//int HangmanModel::getLives() {
//	return lives;
//}

string HangmanModel::getRandMovie() const {
	return this->randMovie;
}

string HangmanModel::getCurrentStatus() const {
	return this->currentStatus;
}

void HangmanModel::setCurrentStatus(string currentStatus) {
	this->currentStatus = currentStatus;
}

void HangmanModel::decreaseLivesByOne() {
	this->lives -= 1;
}
int HangmanModel::getLives() const{
	return this->lives;
}

void HangmanModel::setAllGuesses(char c) {
	this->allGuesses.push_back(c);
}

string HangmanModel::getAllGuesses() {
	return this->allGuesses;
}