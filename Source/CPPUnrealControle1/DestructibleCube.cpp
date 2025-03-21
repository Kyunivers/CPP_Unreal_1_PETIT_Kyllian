#include "DestructibleCube.h"

// Constructeur
ADestructibleCube::ADestructibleCube()
{
	// Activer le tick de l'acteur
	PrimaryActorTick.bCanEverTick = true;

    // Cr�er et attacher le composant Mesh
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    // Charger un cube de base d'Unreal Engine
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }
}

// Appel�e au d�but du jeu
void ADestructibleCube::BeginPlay()
{
	Super::BeginPlay();
}

// Appel�e � chaque frame
void ADestructibleCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Impl�mentation de la fonction DestroyObject
void ADestructibleCube::DestroyObject_Implementation()
{
	// La logique pour d�truire l'acteur
	Destroy();
}
