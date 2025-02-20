#include "Tests.h"
#include "Service.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;
void testMovie() {
    Movie movie;
    assert(movie.getTitle() == "");
    assert(movie.getGenre() == "");
    assert(movie.getTrailer() == "");
    assert(movie.getYear() == 0);
    assert(movie.getLikes() == 0);
    movie = movie;
    Movie movie2{ "The Shawshank Redemption", "Drama", 1994, 0, "https://www.youtube.com/watch?v=6hB3S9bIaco" };
    assert(movie2.getTitle() == "The Shawshank Redemption");
    assert(movie2.getGenre() == "Drama");
    assert(movie2.getTrailer() == "https://www.youtube.com/watch?v=6hB3S9bIaco");
    assert(movie2.getYear() == 1994);
    assert(movie2.getLikes() == 0);
    try {
        movie2.isValidMovie();
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }
    assert(movie2.isValidTrailer("58gdu") == false);
    assert(movie2.isValidYear(-1) == false);
    assert(movie2.isValidLikes(-1) == false);
    try
    {
        movie2.setYear(-1);
        assert(false);
    }
    catch (exception&)
    {
        assert(true);
    }
    try
    {
        movie2.setLikes(-1);
        assert(false);
    }
    catch (exception&)
    {
        assert(true);
    }
    Movie movie3{ movie2 };
    assert(movie3.getTitle() == "The Shawshank Redemption");
    assert(movie3.getGenre() == "Drama");
    assert(movie3.getTrailer() == "https://www.youtube.com/watch?v=6hB3S9bIaco");
    assert(movie3.getYear() == 1994);
    assert(movie3.getLikes() == 0);
    string t = "Titanic";
    movie.setTitle(t);
    assert(movie.getTitle() == "Titanic");
    string g = "Romance";
    movie.setGenre(g);
    assert(movie.getGenre() == "Romance");
    string tr = "https://www.youtube.com/watch?v=kVrqfYjkTdQ";
    movie.setTrailer(tr);
    assert(movie.getTrailer() == "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
    movie.setYear(1997);
    assert(movie.getYear() == 1997);
    movie.setLikes(13);
    assert(movie.getLikes() == 13);
    movie = movie2;
    assert(movie.getTitle() == "The Shawshank Redemption");
    assert(movie.getGenre() == "Drama");
    assert(movie.getTrailer() == "https://www.youtube.com/watch?v=6hB3S9bIaco");
    assert(movie.getYear() == 1994);
    assert(movie.getLikes() == 0);
    assert(movie.isValidTrailer("https://www.youtube.com/watch?v=6hB3S9bIaco") == true);
}
void testRepo() {
    Repository repo;
    assert(repo.getLength() == 0);
    Movie movie("The Shawshank Redemption", "Drama", 1994, rand() % 100 + 1, "https://www.youtube.com/watch?v=6hB3S9bIaco");
    repo.addMovie(movie);
    assert(repo.getLength() == 1);
    int prevLikes = repo.getMovie(0).getLikes();
    repo.modifyLikes(0, 123);
    assert(repo.getMovie(0).getLikes() == prevLikes + 123);
    Movie movieToRemove("The Shawshank Redemption", "Drama", 1994, rand() % 100 + 1, "https://www.youtube.com/watch?v=6hB3S9bIaco");
    repo.deleteMovie(movieToRemove);
    assert(repo.getLength() == 0);
    Movie movieToUpdate("The Shawshank Redemption", "Drama", 1994, rand() % 100 + 1, "https://www.youtube.com/watch?v=6hB3S9bIaco");
    repo.addMovie(movieToUpdate);
    Movie updatedMovie("IT", "Horror", 2017, rand() % 100 + 1, "https://www.youtube.com/watch?v=FnCdOQsX5kc");
    int pos = repo.getPosition(movieToUpdate);
    assert(pos != -1);
    repo.updateMovie(pos, updatedMovie);
    assert(repo.getLength() == 1);
    try
    {
        repo.getMovie(-1);
        assert(false);
    }
    catch (exception&)
    {
        assert(true);
    }
    try
    {
        repo.getMovie(53262);
        assert(false);
    }
    catch (exception&)
    {
        assert(true);
    }
    assert(repo.getMovie(0).getTitle() == "IT");
    assert(repo.getMovie(0).getGenre() == "Horror");
    assert(repo.getMovie(0).getTrailer() == "https://www.youtube.com/watch?v=FnCdOQsX5kc");
    assert(repo.getMovie(0).getYear() == 2017);
    assert(repo.getMovie(0).getLikes() <= 100);
    assert(repo.isValidPosition(0) == true);
    assert(repo.isValidPosition(1) == false);
    assert(repo.isValidPosition(-1) == false);
    assert(repo.getLength() == 1);
    assert(repo.getMovie(0).getTitle() == "IT");
    assert(repo.getMovie(0).getGenre() == "Horror");
    assert(repo.getMovie(0).getTrailer() == "https://www.youtube.com/watch?v=FnCdOQsX5kc");
    assert(repo.getMovie(0).getYear() == 2017);
    assert(repo.getMovie(0).getLikes() <= 100);
    assert(repo.getLength() == 1);
    assert(repo.getMovie(0).getTitle() == "IT");
    assert(repo.getMovie(0).getGenre() == "Horror");
    assert(repo.getMovie(0).getTrailer() == "https://www.youtube.com/watch?v=FnCdOQsX5kc");
    assert(repo.getMovie(0).getYear() == 2017);
    assert(repo.getMovie(0).getLikes() <= 100);
}
void testService() {
    Service service = Service();
    std::string first = "abc";
    std::string second = "abc";
    assert(service.cmpstr(first, second) == true);
    std::string first1 = "HEY";
    std::string second1 = "hey";
    assert(service.cmpstr(first1, second1) == true);
    std::string first3 = "abc";
    std::string second3 = "abcd";
    assert(service.cmpstr(first3, second3) == false);
    std::string first4 = "abc";
    std::string second4 = "abd";
    assert(service.cmpstr(first4, second4) == false);
    srand(time(NULL));
    try
    {
        service.getMovie(-1);
        assert(false);
    }
    catch (exception&)
    {
        assert(true);
    }
    assert(service.getSize() == 0);
    service.setCredentials(true);
    assert(service.getCredentials() == true);
    service.setCredentials(false);
    assert(service.getCredentials() == false);
    service.hardCodedMovies();
    assert(service.getSize() == 15);
    Movie movieToBeAdded = Movie("Harry Potter", "Fantasy", 2001, rand() % 100 + 1, "https://www.youtube.com/watch?v=VyHV0BRtdxo");
    //assert(service.userRemove(23) == false);
    service.addMovie(movieToBeAdded);
    int likes = service.getMovie(15).getLikes();
    assert(service.getSize() == 16);
    //service.increaseLikes(15);
    assert(service.getMovie(15).getLikes() == likes + 1);
    service.userRemove(2);
    assert(service.getSize() == 15);
    Movie updatedMovie = Movie("Harry Potter and the Chamber of Secrets", "Fantasy", 2002, rand() % 100 + 1, "https://www.youtube.com/watch?v=VyHV0BRtdxo");
    std::vector<Movie> currentMovies = service.getAllMovies();
    int pos = std::distance(currentMovies.begin(), std::find(currentMovies.begin(), currentMovies.end(), movieToBeAdded));
    assert(pos != -1);
    //assert(service.updateMovie(pos, updatedMovie) == true); 
    assert(service.getSize() == 15);
    assert(service.getMovie(pos).getTitle() == "Harry Potter and the Chamber of Secrets");
    assert(service.getMovie(pos).getGenre() == "Fantasy");
    assert(service.getMovie(pos).getTrailer() == "https://www.youtube.com/watch?v=VyHV0BRtdxo");
    assert(service.getMovie(pos).getYear() == 2002);
    assert(service.getMovie(pos).getLikes() <= 100);
    //assert(service.addMovie(updatedMovie) == false);
    std::vector<Movie> movies = service.getAllMovies();
    assert(movies.size() == 15);
    string a = "Action";
}

void testAll() {
    testMovie();
    testRepo();
    testService();
}