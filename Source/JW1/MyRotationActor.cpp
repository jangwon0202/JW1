// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRotationActor.h"

// Sets default values
AMyRotationActor::AMyRotationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyRotationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyRotationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, 90.0f * DeltaTime, 0.0f)); // 1. 매 프레임마다 Y축(Pitch)을 기준으로 90도씩 회전.

	static float RunningTime = 0.0f; // 2. 위아래로 부드럽게 둥실둥실 띄우는 수학 공식 코드
	RunningTime += DeltaTime;

	float Deltaheight = FMath::Sin(RunningTime * 3.0f) * 20.0f; // sin 함수는 -1에서 1 사이의 값을 반환하므로, 3.0f를 곱해서 속도를 조절하고, 2.0f를 곱해서 높이를 조절합니다.
	AddActorLocalOffset(FVector(0.0f, 0.0f, Deltaheight));

}

