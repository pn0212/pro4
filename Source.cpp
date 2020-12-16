//
//  Source.cpp
//  Project 4
//
//  Created by Felix Minh Thong Vu on 11/4/20.
//

#include <stdio.h>
#include "Header.h"
#include <iostream>
#include <string.h>

Url::Url(std::string url)
    : _url{ url } {
        size_t colon_pos = url.find_first_of(":");
        std::string scheme = url.substr(0,colon_pos + 1);
        
        std::string s_new = url.substr(colon_pos + 3);
        
        size_t two_forward_slash_pos = url.find_first_of("//");
        size_t forward_slash_pos = s_new.find_first_of("/");
        std::string authority = url.substr(two_forward_slash_pos,forward_slash_pos + 2);
        
        std::string path = s_new.substr(forward_slash_pos);

        _scheme = scheme;
        _authority = authority;
        _path = path;
    }

std::string Url::getUrl()
{
    return _url;
}

std::string Url::getScheme()
{
    return _scheme;
}

std::string Url::getAuthority()
{
    return _authority;
}

std::string Url::getPath()
{
    return _path;
}

void parseUrlInformation(Url url)
{
    std::cout << "URL = " << url.getUrl() << "\n" << "scheme = " << url.getScheme() << "\n" << "authority = " << url.getAuthority() << "\n" << "path = " << url.getPath() << "\n";
}

Image::Image(std::string fileName, std::string imageType, long date, double size, std::string authorName, long width, long height, int apertureSize, std::string exposureTime, int isoValue, bool flash)
    : _fileName{ fileName }, _imageType{ imageType }, _date{ date }, _size{ size}, _authorName{ authorName }, _width{ width }, _height{ height }, _apertureSize{ apertureSize }, _exposureTime{ exposureTime }, _isoValue{ isoValue }, _flash{ flash } {}

std::string Image::getFileName(){
    return _fileName;
}

std::string Image::getImageType(){
    return _imageType;
}

long Image::getDate(){
    return _date;
}

double Image::getSize(){
    return _size;
}

std::string Image::getAuthorName(){
    return _authorName;
}

long Image::getWidth(){
    return _width;
}

long Image::getHeight(){
    return _height;
}

int Image::getApertureSize(){
    return _apertureSize;
}

std::string Image::getExposureTime(){
    return _exposureTime;
}

int Image::getIsoValue(){
    return _isoValue;
}

bool Image::getFlash(){
    return _flash;
}

void Image::setFileName(std::string file)
{
    _fileName = file;
}

void Image::setImageType(std::string type)
{
    if (type == "PNG" || type == "GIF" || type == "JPEG"){
        _imageType = type;
    }
    else {
        _imageType = "Invalid type";
    }
}

void Image::setDate(long date){
    _date = date;
}

void Image::setSize(double size){
    _size = size;
}

void Image::setAuthorName(std::string author){
    _authorName = author;
}

void Image::setWidth(long width){
    _width = width;
}

void Image::setHeight(long height){
    _height = height;
}

void Image::setAperureSize(int aperture){
    _apertureSize = aperture;
}

void printImageInformation(Image image)
{
    std::cout << "File name = " << image.getFileName() << "\n" << "Image type = " << image.getImageType() << "\n" << "Date = " << image.getDate() << "\n" << "Size = " << image.getSize() << " MB\n" << "Author name = " << image.getAuthorName() << "\n" << "Dimension = " << image.getWidth() << " width " << image.getHeight() << " height\n" << "Aperture size = f/" << image.getApertureSize() << "\n" << "Exposure time = " << image.getExposureTime() << "\n" << "ISO value = " << image.getIsoValue() << "\n" << "Flash enabled = " << image.getFlash() << "\n";
}

Item::Item(std::string name, long id, double price, int quantity): _name{ name }, _id{ id }, _price {price}, _quantity { quantity }{}

std::string Item::getName(){
    return _name;
}

long Item::getId(){
    return _id;
}

double Item::getPrice(){
    return _price;
}

int Item::getQuantity(){
    return _quantity;
}

Store::Store(): _books{ "books", 700000, 25, 12},_coloredPencils{ "colored pencils", 600000, 15, 15}, _coloringPaper{"coloring papers", 500000, 20, 20}, _markers{ "markers", 400000, 2, 50}, _crayons{ "crayons", 300000, 2, 3}, _staples{"staples", 200000, 1, 7}{}

int Store::getTotal(){
    return _books.getQuantity() + _coloredPencils.getQuantity() + _coloringPaper.getQuantity() + _crayons.getQuantity() + _markers.getQuantity() + _staples.getQuantity();
}

void Store::printStoreInformation(){
    std::cout << "Store:\n" << "Books x " << _books.getQuantity() << "\n" << "Colored Pencils x " << _coloredPencils.getQuantity() << "\n" << "Coloring Paper x " << _coloringPaper.getQuantity() << "\n" << "Crayons x " << _crayons.getQuantity() << "\n" << "Markers x " << _markers.getQuantity() << "\n" << "Staples x " << _staples.getQuantity() << "\n";
}

Order::Order(): _books{ "books", 700000, 25, 0},_coloredPencils{ "colored pencils", 600000, 15, 0}, _coloringPaper{"coloring papers", 500000, 20, 0}, _markers{ "markers", 400000, 2, 0}, _crayons{ "crayons", 300000, 2, 0}, _staples{"staples", 200000, 1, 0}{}

void Order::addItem(std::string name){
    if (name == _books.getName()){
        int totalBooks = _books.getQuantity() + 1;
        _books.updateItem(totalBooks);
    }
    if (name == _coloredPencils.getName()){
        int totalPencils = _coloredPencils.getQuantity() + 1;
        _coloredPencils.updateItem(totalPencils);
    }
    if (name == _coloringPaper.getName()){
        int totalPaper = _coloringPaper.getQuantity() + 1;
        _coloringPaper.updateItem(totalPaper);
    }
    if (name == _crayons.getName()){
        int totalCrayons = _crayons.getQuantity() + 1;
        _crayons.updateItem(totalCrayons);
    }
    if (name == _markers.getName()){
        int totalMarkers = _markers.getQuantity() + 1;
        _markers.updateItem(totalMarkers);
    }
    if (name == _staples.getName()){
        int totalStaples = _staples.getQuantity() + 1;
        _staples.updateItem(totalStaples);
    }
}

void Item::updateItem(int number){
    _quantity = number;
}

int Order::getTotalPrice(){
    return _books.getPrice() * _books.getQuantity() + _coloredPencils.getPrice() * _coloredPencils.getQuantity() + _coloringPaper.getPrice() * _coloringPaper.getQuantity() + _crayons.getPrice() * _crayons.getQuantity() + _markers.getPrice() * _markers.getQuantity() + _staples.getPrice() * _staples.getQuantity();
}
