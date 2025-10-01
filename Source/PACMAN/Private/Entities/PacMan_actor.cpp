// Fill out your copyright notice in the Description page of Project Settings.

#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Entities/PacMan_actor.h"

#include "Components/BoxComponent.h"


// Sets default values
APacMan_actor::APacMan_actor()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCollision->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	BoxCollision->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void APacMan_actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APacMan_actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APacMan_actor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PacManMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APacMan_actor::Move);
	}
	
}

void APacMan_actor::Move(const FInputActionInstance& Inst)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Move Action Trigged")));
	FVector2d MoveInputValue = Inst.GetValue().Get<FVector2D>();
	AddMovementInput(FVector(MoveInputValue.X, MoveInputValue.Y, 0.f), 1.f);
}

