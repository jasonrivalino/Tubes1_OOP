#include "ability_card.hpp"
#include <iostream>
using namespace std;

ReRoll::ReRoll() : Card("ReRoll"){
}

ReRoll::~ReRoll(){
    //dtor
}

void ReRoll::setReRoll(bool adaCard){
    this -> available = adaCard;
}

bool ReRoll::getReRoll(){
    return this -> available;
}

void ReRoll::ReRollEffect(){
    // Masukin efeknya
}

Quadruple::Quadruple() : Card("Quadruple"){
}

Quadruple::~Quadruple(){
    //dtor
}

void Quadruple::setQuadruple(bool adaCard){
    this -> available = adaCard;
}

bool Quadruple::getQuadruple(){
    return this -> available;
}

void Quadruple::QuadrupleEffect(){
    // Masukin efeknya
}

Quarter::Quarter() : Card("Quarter"){
}

Quarter::~Quarter(){
    //dtor
}

void Quarter::setQuarter(bool adaCard){
    this -> available = adaCard;
}

bool Quarter::getQuarter(){
    return this -> available;
}

void Quarter::QuarterEffect(){
    // Masukin efeknya
}

ReverseDirection::ReverseDirection() : Card("ReverseDirection"){
}

ReverseDirection::~ReverseDirection(){
    //dtor
}

void ReverseDirection::setReverseDirection(bool adaCard){
    this -> available = adaCard;
}

bool ReverseDirection::getReverseDirection(){
    return this -> available;
}

void ReverseDirection::ReverseDirectionEffect(){
    // Masukin efeknya
}

swap_card::swap_card() : Card("swap_card"){
}

swap_card::~swap_card(){
    // dtor
}

void swap_card::setSwapCard(bool adaCard){
    this -> available = adaCard;
}

bool swap_card::getSwapCard(){
    return this -> available;
}

void swap_card::swap_card(){
    // Masukin efeknya
}

switch::switch() : Card("switch"){
}

switch::~switch(){
    // dtor
}

void switch::setSwitch(bool adaCard){
    this -> available = adaCard;
}

bool switch::getSwitch(){
    return this -> available;
}

void switch::SwitchEffect(){
    // Masukin efeknya
}

abilityless::abilityless() : Card("abilityless"){
}

abilityless::~abilityless(){
    // dtor
}

void abilityless::setAbilityless(bool adaCard){
    this -> available = adaCard;
}

bool abilityless::getAbilityless(){
    return this -> available;
}

void abilityless::abilitylessEffect(){
    // Masukin efeknya
}