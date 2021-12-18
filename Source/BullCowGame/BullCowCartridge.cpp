// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() {
  Super::BeginPlay();
  InitializeGame();

  PrintLine(TEXT("The Hidden Word is %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());  // Debugging
  PrintLine(TEXT("Welcome to BullCow!"));
  PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
  PrintLine(TEXT("You have %i lives left"), Lives);
}

void UBullCowCartridge::OnInput(const FString &Input) {  // When the player hits enter

  ClearScreen();

  // Once the user types a word, we check against the hidden word.
  // If they match, you win. If not, you lose.
  if (Input == HiddenWord) {
    PrintLine(TEXT("You win!"));
  } else {
    if (Input.Len() != HiddenWord.Len()) {
      PrintLine(TEXT("Try again! The Hidden Word is %i characters long."), HiddenWord.Len());
    }
    PrintLine(TEXT("You Lose!"));
  }
}

void UBullCowCartridge::InitializeGame() {
  HiddenWord = TEXT("what");
  Lives = 4;
}
