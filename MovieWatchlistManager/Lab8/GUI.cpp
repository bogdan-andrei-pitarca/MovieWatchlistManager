#include "GUI.h"
using namespace std;
AdminGUI::AdminGUI(Service& service, QWidget* parent) : QWidget(parent), service(service) {
    QHBoxLayout* admin = new QHBoxLayout;
    QVBoxLayout* movieStuff = new QVBoxLayout;
    QHBoxLayout* moviesTitle = movieTitle();
    QHBoxLayout* moviesGenre = movieGenre();
    QHBoxLayout* moviesYear = movieYear();
    QHBoxLayout* moviesLikes = movieLikes();
    QHBoxLayout* moviesTrailer = movieTrailer();
    QHBoxLayout* buttons = allButtons();
    movieStuff->setSpacing(25);
    movieStuff->addLayout(moviesTitle);
    movieStuff->addLayout(moviesGenre);
    movieStuff->addLayout(moviesYear);
    movieStuff->addLayout(moviesLikes);
    movieStuff->addLayout(moviesTrailer);
    movieStuff->addLayout(buttons);
    this->createTable();
    admin->addWidget(movieTable);
    this->setLayout(admin);
    admin->addLayout(movieStuff);
    QObject::connect(this->addButton, &QPushButton::pressed, this, &AdminGUI::addMovieSlot);
    QObject::connect(this->deleteButton, &QPushButton::pressed, this, &AdminGUI::deleteMovieSlot);
    QObject::connect(this->updateButton, &QPushButton::pressed, this, &AdminGUI::updateMovieSlot);
}
QHBoxLayout* AdminGUI::allButtons() {
    QHBoxLayout* buttons = new QHBoxLayout();
    this->addButton = new QPushButton("Add Movie", this);
    this->deleteButton = new QPushButton("Delete Movie", this);
    this->updateButton = new QPushButton("Update Movie", this);
    buttons->addWidget(addButton);
    buttons->addWidget(deleteButton);
    buttons->addWidget(updateButton);
    return buttons;
}
QHBoxLayout* AdminGUI::movieTitle() {
    QLabel* title = new QLabel("MOVIE TITLE", this);
    this->titleInput = new QLineEdit(this);
    QHBoxLayout* titleLayout = new QHBoxLayout();
    titleLayout->addWidget(title);
    titleLayout->addWidget(titleInput);
    return titleLayout;
}
QHBoxLayout* AdminGUI::movieGenre() {
    QLabel* genre = new QLabel("MOVIE GENRE", this);
    this->genreInput = new QLineEdit(this);
    QHBoxLayout* genreLayout = new QHBoxLayout();
    genreLayout->addWidget(genre);
    genreLayout->addWidget(genreInput);
    return genreLayout;
}
QHBoxLayout* AdminGUI::movieYear() {
    QLabel* year = new QLabel("MOVIE YEAR", this);
    this->yearInput = new QLineEdit(this);
    QHBoxLayout* yearLayout = new QHBoxLayout();
    yearLayout->addWidget(year);
    yearLayout->addWidget(yearInput);
    return yearLayout;
}
QHBoxLayout* AdminGUI::movieLikes() {
    QLabel* likes = new QLabel("MOVIE LIKES", this);
    this->likesInput = new QLineEdit(this);
    QHBoxLayout* likesLayout = new QHBoxLayout();
    likesLayout->addWidget(likes);
    likesLayout->addWidget(likesInput);
    return likesLayout;
}
QHBoxLayout* AdminGUI::movieTrailer() {
    QLabel* trailer = new QLabel("MOVIE TRAILER", this);
    this->trailerInput = new QLineEdit(this);
    QHBoxLayout* trailerLayout = new QHBoxLayout();
    trailerLayout->addWidget(trailer);
    trailerLayout->addWidget(trailerInput);
    return trailerLayout;
}
void AdminGUI::createTable() {
    this->movieTable = new QTableWidget();
    QStringList header = { "TITLE", "GENRE", "YEAR OF RELEASE", "NR OF LIKES", "TRAILER" };
    movieTable->setColumnCount(5);
    movieTable->setColumnWidth(0, 400);
    movieTable->setHorizontalHeaderLabels(header);
    for (auto& movie : this->service.getAllMovies()) 
        addMovieToTable(movie);
}
void AdminGUI::addMovieToTable(Movie& movie) {
    int rows = movieTable->rowCount();
    movieTable->insertRow(rows);
    movieTable->setItem(rows, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
    movieTable->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
    movieTable->setItem(rows, 2, new QTableWidgetItem(QString::number(movie.getYear())));
    movieTable->setItem(rows, 3, new QTableWidgetItem(QString::number(movie.getLikes())));
    movieTable->setItem(rows, 4, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
}
void AdminGUI::addMovieSlot() {
    string title = this->titleInput->text().toStdString();
    string genre = this->genreInput->text().toStdString();
    string trailer = this->trailerInput->text().toStdString();
    int year = this->yearInput->text().toInt();
    int likes = this->likesInput->text().toInt();
    try {
        Validator::validateMovie(title, genre, to_string(year), to_string(likes), trailer);
        Movie movie = Movie(title, genre, year, likes, trailer);
        this->service.addMovie(movie);
        this->addMovieToTable(movie);
        this->titleInput->clear();
        this->genreInput->clear();
        this->trailerInput->clear();
        this->yearInput->clear();
        this->likesInput->clear();
    }
    catch (MovieException& exception) {
        QMessageBox::critical(this, "Error", "Invalid stuff!\n");
    }
    catch (DuplicateException& exception) {
        QMessageBox::critical(this, "Error", exception.what());
    }
}
void AdminGUI::deleteMovieSlot() {
    int row = this->movieTable->currentRow();
    try {
        this->service.adminRemoveByPosition(row-1);
    }
    catch (InvalidPositionException& e){
        QMessageBox::critical(this, "Error", e.what());
    }
    this->movieTable->removeRow(row);
}
void AdminGUI::updateMovieSlot() {
    string title = this->titleInput->text().toStdString();
    string genre = this->genreInput->text().toStdString();
    string trailer = this->trailerInput->text().toStdString();
    int year = this->yearInput->text().toInt();
    int likes = this->likesInput->text().toInt();
    int row = this->movieTable->currentRow();
    try {
        Validator::validateMovie(title, genre, to_string(year), to_string(likes), trailer);
        Movie movie = Movie(title, genre, year, likes, trailer);
        this->service.updateMovie(row, movie);
        this->movieTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(title)));
        this->movieTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(genre)));
        this->movieTable->setItem(row, 2, new QTableWidgetItem(QString::number(year)));
        this->movieTable->setItem(row, 3, new QTableWidgetItem(QString::number(likes)));
        this->movieTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(trailer)));
    }
    catch (MovieException& e) {
        QMessageBox::critical(this, "Error", "Invalid stuff!\n");
    }
    catch (InvalidPositionException& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
    catch (DuplicateException& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}
UserGUI::UserGUI(Service& service, QWidget* parent) : QWidget(parent), service{ service } {
    QHBoxLayout* layout1 = new QHBoxLayout();
    QVBoxLayout* layout2 = new QVBoxLayout;
    QHBoxLayout* layout3 = this->watchlistLayout();
    QHBoxLayout* genreFilterLayout = this->genreFilter();
    QVBoxLayout* deleteMovieLayout = this->deleteMovie();
    QVBoxLayout* watchlistInfoLayout = this->watchlistInfo(genreFilterLayout, deleteMovieLayout);
    layout2->addLayout(layout3);
    layout1->addLayout(layout2);
    layout1->addLayout(watchlistInfoLayout);
    this->setLayout(layout1);
    this->connectSignalsAndSlots();
}
QHBoxLayout* UserGUI::watchlistLayout() {
    QHBoxLayout* watchlist = new QHBoxLayout;
    QLabel* label = new QLabel("WATCHLIST FORMAT", this);
    watchlistType = new QComboBox(this);
    watchlistType->addItem("Please select:");
    watchlistType->addItem("CSV");
    watchlistType->addItem("HTML");
    watchlist->addWidget(label);
    watchlist->addWidget(watchlistType);
    return watchlist;
}
QHBoxLayout* UserGUI::titleLayout() {
    QLabel* title = new QLabel("MOVIE TITLE", this);
    titleInput = new QLineEdit(this);
    QHBoxLayout* titleLayout = new QHBoxLayout;
    titleLayout->addWidget(title);
    titleLayout->addWidget(titleInput);
    return titleLayout;
}
QHBoxLayout* UserGUI::genreLayout() {
    QLabel* genre = new QLabel("MOVIE GENRE", this);
    genreInput = new QLineEdit(this);
    QHBoxLayout* genreLayout = new QHBoxLayout;
    genreLayout->addWidget(genre);
    genreLayout->addWidget(genreInput);
    return genreLayout;
}
QHBoxLayout* UserGUI::yearLayout() {
    QLabel* year = new QLabel("MOVIE YEAR", this);
    yearInput = new QLineEdit(this);
    QHBoxLayout* yearLayout = new QHBoxLayout;
    yearLayout->addWidget(year);
    yearLayout->addWidget(yearInput);
    return yearLayout;
}
QHBoxLayout* UserGUI::genreFilter() {
    QHBoxLayout* genre = new QHBoxLayout;
    QLabel* genreFilter = new QLabel("FIND BY GENRE", this);
    genreFilterInput = new QLineEdit(this);
    this->moviesByGenre = new QPushButton("GET MOVIES", this);
    genre->addWidget(genreFilter);
    genre->addWidget(genreFilterInput);
    genre->addWidget(moviesByGenre);
    return genre;
}
QVBoxLayout* UserGUI::deleteMovie() {
    QVBoxLayout* delMovie = new QVBoxLayout;
    QLabel* delMovieWatchlist = new QLabel("ENTER INDEX:", this);
    index = new QLineEdit(this);
    this->deleteButton = new QPushButton("DELETE FROM WATCHLIST", this);
    this->likeAndDelete = new QPushButton("LIKE AND DELETE", this);
    delMovie->addWidget(delMovieWatchlist);
    delMovie->addWidget(index);
    QHBoxLayout* buttons = new QHBoxLayout;
    buttons->addWidget(likeAndDelete);
    buttons->addWidget(deleteButton);
    delMovie->addLayout(buttons);
    return delMovie;
}
QHBoxLayout* UserGUI::buttonsLayout() {
    QHBoxLayout* buttons = new QHBoxLayout;
    this->addButton = new QPushButton("ADD MOVIE", this);
    this->nextMovie = new QPushButton("GET THE NEXT MOVIE", this);
    this->exportWatchlist = new QPushButton("GET WATCHLIST", this);
    buttons->addWidget(addButton);
    buttons->addWidget(nextMovie);
    buttons->addWidget(exportWatchlist);
    return buttons;
}
QVBoxLayout* UserGUI::watchlistInfo(QHBoxLayout* genreFilter, QVBoxLayout* deleteMovie) {
    QVBoxLayout* movie = new QVBoxLayout;
    QHBoxLayout* buttons = this->buttonsLayout();
    QHBoxLayout* title = this->titleLayout();
    QHBoxLayout* genre = this->genreLayout();
    QHBoxLayout* year = this->yearLayout();
    movie->setSpacing(25);
    movie->addLayout(genreFilter);
    movie->addLayout(title);
    movie->addLayout(genre);
    movie->addLayout(year);
    movie->addLayout(buttons);
    movie->addLayout(deleteMovie);
    return movie;
}
void UserGUI::filterByGenreSlot() {
    this->titleInput->setText("");
    this->genreInput->setText("");
    this->yearInput->setText("");
    auto res = this->service.getMoviesByGenre(genreFilterInput->text().toStdString());
    if (!res.empty()) {
        Movie movie = this->service.getCurrentMovie();
        this->titleInput->setText(QString::fromStdString(movie.getTitle()));
        this->genreInput->setText(QString::fromStdString(movie.getGenre()));
        this->yearInput->setText(QString::fromStdString(to_string(movie.getYear())));
    }
    else QMessageBox::information(this, "Info", "No such movies!\n");
}
void UserGUI::deleteSlot() {
    int index = this->index->text().toInt();
    if (index == 0 && this->index->text().toStdString() != "0"){
        QMessageBox::information(this, "Info", "Not a valid position!\n");
        return;
    }
    try {
        this->service.removeWatchedMovie(index-1, false);
        QMessageBox::information(this, "Info", "Movie deleted!\n");
    }
    catch (InvalidPositionException& e) {
        QMessageBox::information(this, "Info", "Invalid position!\n");
        return;
    }
}
void UserGUI::addMovieSlot() {
    if (this->titleInput->text().isEmpty()) {
        QMessageBox::information(this, "Info", "Invalid!\n");
        return;
    }
    try {
        this->service.addCurrentMovie();
        QMessageBox::information(this, "Info", "Movie added!\n");
    }
    catch (DuplicateException& e) {
        QMessageBox::information(this, "Info", "invalid\n");
        return;
    }
}
void UserGUI::nextSlot() {
    if (this->titleInput->text().isEmpty()) {
        QMessageBox::information(this, "Info", "Invalid!\n");
        return;
    }
    this->service.increment();
    Movie movie = this->service.getCurrentMovie();
    this->titleInput->setText(QString::fromStdString(movie.getTitle()));
    this->genreInput->setText(QString::fromStdString(movie.getGenre()));
    this->yearInput->setText(QString::fromStdString(to_string(movie.getYear())));
}
void UserGUI::exportWatchlistSlot() {
    try {
        this->service.display();
    }
    catch (FileException& e) {
        QMessageBox::information(this, "Info", e.what());
        return;
    }
}
void UserGUI::likeAndDeleteSlot() {
    cout << "Like and delete!" << endl;
    int index = this->index->text().toInt();
    if (index == 0 && this->index->text().toStdString() != "0") {
        QMessageBox::information(this, "Info", "Enter a valid position!\n");
        return;
    }
    try {
        this->service.removeWatchedMovie(index-1, true);
        QMessageBox::information(this, "Info", "Successfully deleted!\n");
    }
    catch (InvalidPositionException& e) {
        QMessageBox::information(this, "Info", e.what());
        return;
    }
}
void UserGUI::watchlistTypeSlot() {
    if (this->watchlistType->currentText() == "CSV")
        this->service.setWatchlistType(new CSVWatchlist{ "CSVWatchlist.csv" });
    else
        this->service.setWatchlistType(new HTMLWatchlist{ "HTMLWatchlist.html" });
}
void UserGUI::connectSignalsAndSlots() {
    QObject::connect(this->addButton, &QPushButton::clicked, this, &UserGUI::addMovieSlot);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &UserGUI::deleteSlot);
    QObject::connect(this->moviesByGenre, &QPushButton::clicked, this, &UserGUI::filterByGenreSlot);
    QObject::connect(this->nextMovie, &QPushButton::clicked, this, &UserGUI::nextSlot);
    QObject::connect(this->exportWatchlist, &QPushButton::clicked, this, &UserGUI::exportWatchlistSlot);
    QObject::connect(this->likeAndDelete, &QPushButton::clicked, this, &UserGUI::likeAndDeleteSlot);
    QObject::connect(this->watchlistType, &QComboBox::currentTextChanged, this, &UserGUI::watchlistTypeSlot);
}