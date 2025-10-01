// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "PacEntities.h"
#include "PacMan_actor.generated.h"

class UInputMappingContext;
class UInputAction;
class UInputComponent;
struct FInputActionInstance;

UCLASS()
class PACMAN_API APacMan_actor : public APacEntities
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APacMan_actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputMappingContext* PacManMappingContext;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* IA_Move;


	void Move(const FInputActionInstance& Inst);



	
};
