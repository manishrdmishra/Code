class MovieCatalogue {
private:
std::unordered_map<string, std::vector<Movie>> movies;

public:
MovieCatalogue(const std::string& file) {
    // read from the file
    // parse each line and create Movie object
    
    for(auto& genere: generes) {
         movies[genere].push_back(movies);
    }
   
    // all done then sort 
    
    for(auto& [key, value] : movies) {
        std::sort(value.begin(), value.end(), (auto& first , auto& second)[]{
            return first.year < second.year;
        });
    }
}


std::vector<Movie> getMovies(const std::string genere, const std::string startYear, const std::string endYear) {
    auto genereIt = movies.find(genere);
    auto moviesWithGenere = genereIt->second; // vector 
    auto lowerIt = std::lower_bound(moviesWithGenere.begin(), moviesWithGenere.end(), startYear, (auto& first, auto&second)[]{
        return first.year < second.year;
    });
    
    auto upperIt = std::upper_bound(moviesWithGenere.begin(), moviesWithGenere.end(), endYear, (auto& first, auto&second)[]{
        return first.year < second.year;
    })
    
    std::vector<Movies> results;
    
    std::copy(lowerIt, uppertIt, std::back_inserter(results));
    
    return results;
}
    
}
