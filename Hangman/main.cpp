
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

unsigned int CountWords(const char*);
void ReadWords(const char*, std::string*);
void ClearScreen();
void DisplayMan0();
void DisplayMan1();
void DisplayMan2();
void DisplayMan3();
void DisplayMan4();
void DisplayMan5();
void DisplayMan6();

int main(int argc, const char* argv[])
{
	using namespace std;

	// Count words for allocation and read them in
	const unsigned int kuiWordCount = CountWords(argv[1]);
	string* qpWordArray = new string[kuiWordCount];
	ReadWords(argv[1], qpWordArray);

	// Seed the random number generator with the time
	time_t qTime;
	time(&qTime);
	srand((unsigned int)qTime);

	// An array of function pointers for output 
	void(*pfnaDisplayMan[])() = { DisplayMan0, DisplayMan1, DisplayMan2,
		DisplayMan3, DisplayMan4, DisplayMan5, DisplayMan6 };

	bool bAnotherGame = true;
	// Loop once per game
	do {
		// Pick a random word to guess and get its length
		int iWordChoice = (rand() % kuiWordCount);
		string& qrCurrWord = qpWordArray[iWordChoice];
		const unsigned int kuiWordLength = qrCurrWord.length();

		// Allocate an array to specify guessed letters
		bool* bpGuessed = new bool[kuiWordLength];
		for (unsigned int uiI = 0; uiI < kuiWordLength; ++uiI) {
			bpGuessed[uiI] = false;
		}

		// Initialize game-ending variables
		unsigned int uiWrongGuesses = 0;
		bool bGuessedWord = false;
		bool bGameOver = false;
		// Main game loop
		do {
			// Clear the screen and output the man
			ClearScreen();
			pfnaDisplayMan[uiWrongGuesses]();

			// If there have been 6 wrong gueses or the 
			// word has been guessed then the game is over.
			if (uiWrongGuesses >= 6) {
				cout << "You Lost!" << endl;
				cout << "Answer = " << qrCurrWord << endl;
				bGameOver = true;
			}
			else if (bGuessedWord) {
				cout << qrCurrWord << endl;
				cout << "You Won!" << endl;
				bGameOver = true;
			}
			else {
				// Output '*' or the letters that have been guessed
				for (unsigned int uiI = 0; uiI < kuiWordLength; ++uiI) {
					if (bpGuessed[uiI]) {
						cout << qrCurrWord[uiI];
					}
					else {
						cout << '*';
					}
				}
				cout << endl;
				char cGuess = 0;
				// Get the next guess
				cout << "Next Guess? ";
				cin >> cGuess;

				// Check whether the guess is in the word and fill in
				bool bIsGuessInWord = false;
				for (unsigned int uiI = 0; uiI < kuiWordLength; ++uiI) {
					if (!bpGuessed[uiI] && (qrCurrWord[uiI] == cGuess)) {
						bpGuessed[uiI] = true;
						bIsGuessInWord = true;
					}
				}

				// Increment wrong guesses, if needed
				if (!bIsGuessInWord) {
					++uiWrongGuesses;
				}

				// Check whether all of the letters have been guessed
				bGuessedWord = true;
				for (unsigned int uiI = 0; uiI < kuiWordLength; ++uiI) {
					if (!bpGuessed[uiI]) {
						bGuessedWord = false;
					}
				}
			}
		} while (!bGameOver);

		delete[] bpGuessed;

		// Another game?
		cout << "Play Again? (y/n) ";
		char cPlayAgain = ' ';
		cin >> cPlayAgain;
		if (cPlayAgain == 'n') {
			bAnotherGame = false;
		}
	} while (bAnotherGame);

	delete[] qpWordArray;
	return 0;
}

unsigned int CountWords(const char* kcpFileName) {
	using namespace std;
	unsigned int uiStringCount = 0;
	ifstream qFile(kcpFileName);
	while (!qFile.eof()) {
		string qWord;
		qFile >> qWord;
		// Don't count empty strings
		if (!qWord.empty()) {
			++uiStringCount;
		}
	}
	qFile.close();
	return uiStringCount;
}

void ReadWords(const char* kcpFileName, std::string* qpWordArray) {
	using namespace std;
	unsigned int uiStringCount = 0;
	ifstream qFile(kcpFileName);
	while (!qFile.eof()) {
		string qWord;
		qFile >> qWord;
		// Don't store or count empty strings
		if (!qWord.empty()) {
			qpWordArray[uiStringCount] = qWord;
			++uiStringCount;
		}
	}
	qFile.close();
}

void ClearScreen() {
	using namespace std;
	for (unsigned int uiI = 0; uiI < 20; ++uiI) {
		cout << endl;
	}
}

void DisplayMan0() {
	using namespace std;
	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
}

void DisplayMan1() {
	using namespace std;
	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|     o" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
}

void DisplayMan2() {
	using namespace std;
	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|     o" << endl;
	cout << "|    /" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
}

void DisplayMan3() {
	using namespace std;
	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|     o" << endl;
	cout << "|    /X" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
}

void DisplayMan4() {
	using namespace std;
	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|     o" << endl;
	cout << "|    /X\\" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
}

void DisplayMan5() {
	using namespace std;
	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|     o" << endl;
	cout << "|    /X\\" << endl;
	cout << "|    /" << endl;
	cout << "|" << endl;
}

void DisplayMan6() {
	using namespace std;
	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|     o" << endl;
	cout << "|    /X\\" << endl;
	cout << "|    / \\" << endl;
	cout << "|" << endl;
}