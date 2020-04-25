#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
	string title;
	float rating;
	int duration;
public:
	Movie(string, float, int);
	Movie(string, int);
	~Movie();
	void show();
	void setRating(float);
};

Movie::Movie(string title, float rating, int duration) {
	Movie::title = title;
	if (rating >= 0 && rating <= 10) {
		Movie::rating = rating;
	} else Movie::rating = 0;
	Movie::duration = duration;
}

Movie::Movie(string title, int duration) {
	Movie::title = title;
	Movie::duration = duration;
}

Movie::~Movie() {
	cout << "Объект уничтожен" << endl;
}

void Movie::show() {
	cout << "Название фильма: " << title << endl;
	if (rating >= 0 && rating <= 10) {
		cout << "Рейтинг фильма: " << rating << endl;
	} else cout << "Рейтинг фильма ещё не задан" << endl;
	cout << "Продолжительность фильма: " << duration << endl << endl;
}

void Movie::setRating(float rating) {
	if (rating >= 0 && rating <= 10) {
		Movie::rating = rating;
		cout << "Рейтинг успешно обновлен" << endl << endl;
	} else cout << "Такой рейтинг недопустим" << endl << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	Movie harryPotter("Harry Potter and the Sorcerer's Stone", 8.203, 152);
	Movie fantasticBeasts("Fantastic Beasts and Where to Find Them", 132);
	harryPotter.show();
	fantasticBeasts.show();
	fantasticBeasts.setRating(7.559);
	fantasticBeasts.show();
}