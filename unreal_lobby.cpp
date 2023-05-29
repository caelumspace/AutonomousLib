#include "Lobby.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

ALobby::ALobby()
{
    // Create a dummy player controller to handle input
    DummyPlayerController = CreateDefaultSubobject<APlayerController>(TEXT("DummyPlayerController"));

    // Set the number of players in the lobby to zero
    NumberOfPlayers = 0;
}

void ALobby::BeginPlay()
{
    Super::BeginPlay();

    // Print a message to the screen to indicate that the lobby has started
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Lobby has started!"));
}

void ALobby::AddPlayer()
{
    // Increment the number of players in the lobby
    NumberOfPlayers++;

    // Print a message to the screen to indicate that a player has joined the lobby
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Player %d has joined the lobby"), NumberOfPlayers));
}

void ALobby::RemovePlayer()
{
    // Decrement the number of players in the lobby
    NumberOfPlayers--;

    // Print a message to the screen to indicate that a player has left the lobby
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Player %d has left the lobby"), NumberOfPlayers));
}

void ALobby::StartGame()
{
    // Check if there are enough players to start the game
    if (NumberOfPlayers >= 2)
    {
        // Print a message to the screen to indicate that the game is starting
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Starting game..."));

        // Start the game using the UEngine::Browse() function
        FString MapName = "GameMap";
        GetWorld()->ServerTravel(MapName);
    }
    else
    {
        // Print a message to the screen to indicate that there are not enough players to start the game
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Not enough players to start the game!"));
    }
}
