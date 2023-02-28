#include "ability_card.hpp"
#include <iostream>
using namespace std;

ReRoll::ReRoll() : Card("ReRoll",false){
}

ReRoll::~ReRoll(){
    //dtor
}

void ReRoll::setReRoll(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool ReRoll::getReRoll(){
    return this -> getIsCardUsed();
}

void ReRoll::ReRollEffect(){
    // Masukin efeknya
}

Quadruple::Quadruple() : Card("Quadruple",false){
}

Quadruple::~Quadruple(){
    //dtor
}

void Quadruple::setQuadruple(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool Quadruple::getQuadruple(){
    return getIsCardUsed();
}

void Quadruple::QuadrupleEffect(){
    // Masukin efeknya
}

Quarter::Quarter() : Card("Quarter",false){
}

Quarter::~Quarter(){
    //dtor
}

void Quarter::setQuarter(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool Quarter::getQuarter(){
    return this -> getIsCardUsed();
}

void Quarter::QuarterEffect(){
    // Masukin efeknya
}

ReverseDirection::ReverseDirection() : Card("ReverseDirection",false){
}

ReverseDirection::~ReverseDirection(){
    //dtor
}

void ReverseDirection::setReverseDirection(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool ReverseDirection::getReverseDirection(){
    return this -> getIsCardUsed();
}

void ReverseDirection::ReverseDirectionEffect(){
    // Masukin efeknya
}

SwapCard::SwapCard() : Card("swap_card", false){
}

SwapCard::~SwapCard(){
    // dtor
}

void SwapCard::setSwapCard(bool adaCard){
    setIsCardUsed(adaCard);
}

bool SwapCard::getSwapCard(){
    return this -> getIsCardUsed();
}

void SwapCard::SwapCardEffect(){
    // Masukin efeknya
}

Switch::Switch() : Card("switch",false){
}

Switch::~Switch(){
    // dtor
}

void Switch::setSwitch(bool adaCard){
    setIsCardUsed(adaCard);
}

bool Switch::getSwitch(){
    return this -> getIsCardUsed();
}

void Switch::SwitchEffect(){
    // Masukin efeknya
}

Abilityless::Abilityless() : Card("abilityless", false){
}

Abilityless::~Abilityless(){
    // dtor
}

void Abilityless::setAbilityless(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool Abilityless::getAbilityless(){
    return this -> getIsCardUsed();
}

void Abilityless::AbilitylessEffect(){
    // Masukin efeknya
}