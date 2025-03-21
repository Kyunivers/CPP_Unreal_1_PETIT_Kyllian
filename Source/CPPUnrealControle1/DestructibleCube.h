

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destructible.h"  // Inclusion de l'interface
#include "DestructibleCube.generated.h"

UCLASS()
class CPPUNREALCONTROLE1_API ADestructibleCube : public AActor, public IDestructible
{
	GENERATED_BODY()

public:
	// Constructeur
	ADestructibleCube();

protected:
	// Fonction appelée au début du jeu
	virtual void BeginPlay() override;

public:
	// Fonction appelée chaque frame
	virtual void Tick(float DeltaTime) override;

	// Implémentation de la fonction DestroyObject de l'interface
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void DestroyObject_Implementation() override;  // C'est ici qu'on remplace "DestroyObject()" par "DestroyObject_Implementation()"

private:
	// Composant Mesh du cube
	UPROPERTY(VisibleAnywhere, Category = "Destructible Cube")
	UStaticMeshComponent* CubeMesh;
	
};
