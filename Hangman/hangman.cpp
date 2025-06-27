
//headers file..

#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
int main() {
	
	//setting up the game
	const int MAX_WRONG = 8; //maximum  number of wrong answer before being hanged
	vector<string>words; //collectoin of possible words

	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("PHONE");
	words.push_back("SCHOOL");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; //word to guess
	int wrong = 0;  //number of incorrect guesses;
	string sofar(THE_WORD.size(), '-'); //words guessed so far
	string used = "";
	cout << "Welcome to Hangman\n";
	//main loop

	while ((wrong < MAX_WRONG) && (sofar != THE_WORD)) {
		cout << "You have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left\n";
		cout << "You have used the folowing letters: \n" << used << endl;
		char guess;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess); //make uppercase some secret in uppercase;
		while (used.find(guess) != string::npos) {
			cout << "\n You have alredy guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos) {
			cout << "that's right! " << guess << " is in the word\n";
				//updating sofar to include newly  guessed letters;
			for (int i = 0; i < THE_WORD.length(); i++) {
				if (THE_WORD[i] == guess) {
					sofar[i] = guess;
				}
				}
		}
		else {
			cout << "Sorry, " << guess << " isn't in the word\n";
			wrong++;
		}
	}

	//shutting down;
	if (wrong == MAX_WRONG) {
		cout << "You have been hanged\n";
	}
	else {
		cout << "You have guessed it right";
	}
	cout << "The word was " << THE_WORD << endl;
	return 0;
}
