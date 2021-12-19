// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();
	InitializeGame();
	// PrintLine(TEXT("The Hidden Word is %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());  // Debugging
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
	if (bGameOver)
	{
		ClearScreen();
		InitializeGame();
	}
	else // Process Player Guess
	{
		ProcessGuess(Input);
	}
}

void UBullCowCartridge::InitializeGame()
{
	PrintLine(TEXT("Welcome to BullCow!"));
	HiddenWord = TEXT("what");
	Lives = HiddenWord.Len();
	bGameOver = false;
	PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
	PrintLine(TEXT("You have %i lives."), Lives);
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("Press Enter to Play Again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{

	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("You win!"));
		EndGame();
	}
	if (Guess.Len() != HiddenWord.Len())
	{
		--Lives;
		PrintLine(TEXT("You have lost a life!"));
		PrintLine(TEXT("Try Again!"));

		if (Lives > 0)
		{
			PrintLine(TEXT("You have %i lives left"), Lives);
		}
		else
		{
			PrintLine(TEXT("You are out of lives! \n Game Over!"));
			EndGame();
		}
	}
}
