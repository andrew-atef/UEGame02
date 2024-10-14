// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EchoCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
//#include "GroomComponent.h"
// 
// Sets default values
AEchoCharacter::AEchoCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 330.f, 0.f);


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	/*Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(GetMesh());
	Hair->AttachmentName = FString("head");

	Eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrows"));
	Eyebrows->SetupAttachment(GetMesh());
	Eyebrows->AttachmentName = FString("head");*/
}

// Called when the game starts or when spawned
void AEchoCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEchoCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEchoCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AEchoCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AEchoCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AEchoCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("MoveRL"), this, &AEchoCharacter::MoveRL);

}

void AEchoCharacter::MoveForward(float value)
{
	if (Controller && (value != 0.f))
	{
		const FRotator ControlerRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlerRotation.Yaw, 0.f);

		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		//FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, value);
	}
}

void AEchoCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}

void AEchoCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AEchoCharacter::MoveRL(float value)
{
	if (Controller && (value != 0.f))
	{
		const FRotator ControlerRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlerRotation.Yaw, 0.f);

		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		//FVector Forward = GetActorForwardVector();
		AddMovementInput(Right, value);
		//FVector Right = GetActorRightVector();
		//AddMovementInput(Right, value);
	}
}