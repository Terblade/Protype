﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

UCLASS(config = Game, BlueprintType)
class PROTOTYPE_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	void OnPickupItem(class APrototypeCharacter* Player);

	/* Delegates */
	UFUNCTION()
	void ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	///* Delegates */
	UFUNCTION()
	void ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:

	/** Sphere component used for collision */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* TriggerCollision;
	/*
	* 预览模型
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* PreviewMesh;

	UPROPERTY(EditAnywhere, Category = Item)
	class UTexture2D* InventoryImage;
	
	/*
	* item显示用文本
	*/
	UPROPERTY(EditAnywhere, Category = Item)
	FText PickupText;

	UPROPERTY(EditAnywhere, Category = Item)
	TSubclassOf<class UPickupText> PickupTextClass;

	/*
	* item显示用文本控件
	*/
	UPROPERTY()
	class UPickupText* PickupTextWidget;

private:
	bool bIsInRange;
};