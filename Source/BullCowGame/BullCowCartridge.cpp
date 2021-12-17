// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine (TEXT("Welcome to BullCow!"));
    PrintLine (TEXT("Guess the 4 letter word.")); // TODO: Hardcoded number - Need to refactor for dynamic word length
    PrintLine (TEXT("Press TAB to begin typing\nType anything and press ENTER"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    // Game Loop
        // First clear the Screen, THEN set the hidden word, so the user doesn't see it
    ClearScreen();
    FString HiddenWord = TEXT("what");
    
        // Once the user types a word, we check against the hidden word. 
        // If they match, you win. If not, you lose.
    if (Input == HiddenWord) {
        PrintLine(TEXT("You win!"));
    } else {
        PrintLine(TEXT("You Lose!"));
    }
}

