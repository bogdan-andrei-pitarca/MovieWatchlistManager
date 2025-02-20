#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qlabel.h>
#include <QLineEdit>
#include <qpushbutton.h>
#include <vector>
#include "Movie.h"
#include <QTableWidgetItem>
#include <QComboBox>
#include "Service.h"
#include "Exception.h"
#include "qmessagebox.h"
#include "CSVWatchlist.h"
#include "HTMLWatchlist.h"
class AdminGUI : public QWidget
{
	Q_OBJECT
private:
	Service& service;
public:
	AdminGUI(Service& service, QWidget* parent = nullptr);
	~AdminGUI() {};
	QHBoxLayout* allButtons();
	QHBoxLayout* movieTitle();
	QHBoxLayout* movieGenre();
	QHBoxLayout* movieYear();
	QHBoxLayout* movieLikes();
	QHBoxLayout* movieTrailer();
	void createTable();
	QTableWidget* movieTable;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QLineEdit* titleInput, *genreInput, *trailerInput, *likesInput, *yearInput;
	void addMovieToTable(Movie& movie);
public slots:
	void addMovieSlot();
	void deleteMovieSlot();
	void updateMovieSlot();
};

class UserGUI : public QWidget
{
	Q_OBJECT

private:
	Service& service;
	QPushButton* moviesByGenre, *deleteButton, *likeAndDelete, *nextMovie, *addButton, *exportWatchlist;
	QLineEdit* titleInput, *genreInput, *genreFilterInput, *index, *yearInput;
	QComboBox* watchlistType;
public:
	UserGUI(Service& service, QWidget* parent = nullptr);
	~UserGUI() {};
	QHBoxLayout* watchlistLayout();
	QHBoxLayout* titleLayout();
	QHBoxLayout* genreLayout();
	QHBoxLayout* yearLayout();
	QHBoxLayout* genreFilter();
	QVBoxLayout* deleteMovie();
	QHBoxLayout* buttonsLayout();
	QVBoxLayout* watchlistInfo(QHBoxLayout* genreFilter, QVBoxLayout* deleteMovie);
	void connectSignalsAndSlots();
public slots:
	void filterByGenreSlot();
	void deleteSlot();
	void addMovieSlot();
	void nextSlot();
	void exportWatchlistSlot();
	void watchlistTypeSlot();
	void likeAndDeleteSlot();
};