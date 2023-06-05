#include <iostream>
#include <fstream>
#include <string>

// Base Class
class VideoGame
{
private:
    std::string name;
    std::string genre;
    std::string releaseDate;
    double price;

public:
    VideoGame();
    VideoGame(std::string, std::string, std::string, double);
    VideoGame(std::string, std::string);
    virtual ~VideoGame();
    std::string getName() const;
    std::string getGenre() const;
    std::string getReleaseDate() const;
    double getPrice() const;
    void setName(std::string);
    void setGenre(std::string);
    void setReleaseDate(std::string);
    void setPrice(double);
    virtual std::string printInformation() const;
};

// Constructors
VideoGame::VideoGame(){};
VideoGame::VideoGame(std::string name, std::string genre, std::string releaseDate, double price) : name{name}, genre{genre}, releaseDate{releaseDate}, price{price} {};
VideoGame::VideoGame(std::string name, std::string genre) : name{name}, genre{genre}, releaseDate("Unknown"), price(70){};
// Destructor
VideoGame::~VideoGame()
{
    std::cout << "Destructor Invoked" << std::endl;
}
// Getters
std::string VideoGame::getName() const
{
    return name;
}
std::string VideoGame::getGenre() const
{
    return genre;
}
std::string VideoGame::getReleaseDate() const
{
    return releaseDate;
}
double VideoGame::getPrice() const
{
    return price;
}

// Setters
void VideoGame::setName(std::string name)
{
    this->name = name;
}
void VideoGame::setGenre(std::string genre)
{
    this->genre = genre;
}
void VideoGame::setReleaseDate(std::string releaseDate)
{
    this->releaseDate = releaseDate;
}
void VideoGame::setPrice(double price)
{
    this->price = price;
}

// Information
std::string VideoGame::printInformation() const
{
    return "Video Game : " + name + "\nGenre : " + genre + "\nReleaseDate : " + releaseDate + "\nPrice : " + std::to_string(price) + "\n";
}

// Derived Class
class VideoGameForConsole : public VideoGame
{
private:
    std::string console;

public:
    VideoGameForConsole(std::string, std::string, std::string, double, std::string);
    VideoGameForConsole(const VideoGame &, std::string);
    std::string getConsole() const;
    void setConsole(std::string);
    std::string printInformation() const override;
};
// Constructors
VideoGameForConsole::VideoGameForConsole(std::string name, std::string genre, std::string releaseDate, double price, std::string console) : VideoGame(name, genre, releaseDate, price), console{console} {};
VideoGameForConsole::VideoGameForConsole(const VideoGame &game, std::string console)
{
    setName(game.getName());
    setGenre(game.getGenre());
    setReleaseDate(game.getReleaseDate());
    setPrice(game.getPrice());
    this->console = console;
}
// Extra Getter - Setter
std::string VideoGameForConsole::getConsole() const
{
    return console;
}
void VideoGameForConsole::setConsole(std::string console)
{
    this->console = console;
}
// Override printInformation
std::string VideoGameForConsole::printInformation() const
{
    return "Video Game : " + getName() + "\nGenre : " + getGenre() + "\nReleaseDate : " + getReleaseDate() + "\nPrice : " + std::to_string(getPrice()) + "\nConsole : " + console + "\n";
}

class OutputToFile
{
private:
    std::fstream file;

public:
    OutputToFile(const char *);
    void write(VideoGame *);
    ~OutputToFile();
};

OutputToFile::OutputToFile(const char *toWrite)
{
    file.open(std::string(toWrite), std::fstream::out);
}
void OutputToFile::write(VideoGame *game)
{
    if (file.good())
    {
        file << (game->printInformation()) + "\n";
    }
    else
    {
        std::cout << "Error with File" << std::endl;
    }
}
OutputToFile::~OutputToFile()
{
    std::cout << "Closing File ..." << std::endl;
    file.close();
}

int main()
{
    VideoGame *game1 = new VideoGame("Clash of Clans", "Mobile Game", "20/05/19", 0);
    VideoGame *game2 = new VideoGame("Rainbow Six Siege", "FPS/Shooter", "25/01/20", 45);
    VideoGame *game3 = new VideoGame("Call of Duty Warzone", "FPS/Shooter", "10/09/21", 0);
    VideoGameForConsole *console1 = new VideoGameForConsole((*game3), "PS5");
    std::cout << game1->printInformation();
    printf("\n");
    std::cout << game2->printInformation();
    printf("\n");
    std::cout << game3->printInformation();
    printf("\n");
    std::cout << console1->printInformation();
    printf("\n");
    OutputToFile file1("games.txt");
    file1.write(game1);
    file1.write(game2);
    file1.write(game3);
    file1.write(console1);
    return 0;
}