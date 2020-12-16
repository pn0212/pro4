//
//  Header.h
//  Project 4
//
//  Created by Felix Minh Thong Vu on 11/4/20.
//
#pragma once
#include <string>

class Url {
public:
    Url(std::string url);

    void urlParser(std::string s);
    
    std::string getUrl();
    std::string getScheme();
    std::string getAuthority();
    std::string getPath();

private:
    std::string _url;
    std::string _scheme;
    std::string _authority;
    std::string _path;
};

void parseUrlInformation(Url url);

class Image {
public:
    Image(std::string fileName, std::string imageType, long date, double size, std::string authorName, long width, long height, int apertureSize, std::string exposureTime, int isoValue, bool flash);
        
    std::string getFileName();
    std::string getImageType();
    long getDate();
    double getSize();
    std::string getAuthorName();
    long getWidth();
    long getHeight();
    int getApertureSize();
    std::string getExposureTime();
    int getIsoValue();
    bool getFlash();
    
    void setFileName(std::string file);
    void setImageType(std::string type);
    void setDate(long date);
    void setSize(double size);
    void setAuthorName(std::string author);
    void setWidth(long width);
    void setHeight(long height);
    void setAperureSize(int aperture);
    void setExposureTime(int numerator, int denominator);
    void setIsoValue(int iso);
    void setFlash(bool flash);
    
private:
    std::string _fileName;
    std::string _imageType;
    long _date;
    double _size;
    std::string _authorName;
    long _width;
    long _height;
    int _apertureSize;
    std::string _exposureTime;
    int _isoValue;
    bool _flash;
};

void printImageInformation(Image image);

class Item {
public:
    Item(std::string name, long id, double price, int quantity);
    
    std::string getName();
    long getId();
    double getPrice();
    int getQuantity();
    void updateItem(int number);

    
private:
    std::string _name;
    long _id;
    double _price;
    int _quantity;
};

class Store {
public:
    Store();
    
    int getTotal();
    void printStoreInformation();
    
private:
    Item _books;
    Item _coloredPencils;
    Item _coloringPaper;
    Item _markers;
    Item _crayons;
    Item _staples;
};

class Order {
public:
    Order();
    
    void addItem(std::string name);
    void updateBooks(int number);
    int getTotalPrice();
    
    
private:
    Item _books;
    Item _coloredPencils;
    Item _coloringPaper;
    Item _markers;
    Item _crayons;
    Item _staples;
};


