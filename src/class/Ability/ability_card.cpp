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

SwapCard::SwapCard() : Card("swap_card"){
}

SwapCard::~SwapCard(){
    // dtor
}

void SwapCard::setSwapCard(bool adaCard){
    this -> available = adaCard;
}

bool SwapCard::getSwapCard(){
    return this -> available;
}

void SwapCard::SwapCardEffect(){
    // Masukin efeknya
}

Switch::Switch() : Card("switch"){
}

Switch::~Switch(){
    // dtor
}

void Switch::setSwitch(bool adaCard){
    this -> available = adaCard;
}

bool Switch::getSwitch(){
    return this -> available;
}

void Switch::SwitchEffect(){
    // Masukin efeknya
}

Abilityless::Abilityless() : Card("abilityless"){
}

Abilityless::~Abilityless(){
    // dtor
}

void Abilityless::setAbilityless(bool adaCard){
    this -> available = adaCard;
}

bool Abilityless::getAbilityless(){
    return this -> available;
}

void Abilityless::AbilitylessEffect(){
    // Masukin efeknya
}