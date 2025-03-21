#include "DestructionComponent.h"

// Constructeur
UDestructionComponent::UDestructionComponent()
{
	// Activer l'actualisation chaque frame
	PrimaryComponentTick.bCanEverTick = true;

	// Initialiser la port�e du rayon
	m_Range = 85.0f;

	// Cr�er un composant Camera
	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
}

// Fonction appel�e lorsque le jeu commence ou que l'acteur est initialis�
void UDestructionComponent::BeginPlay()
{
	Super::BeginPlay(); // Appel � la fonction de base pour initialiser correctement le composant
}

// Fonction appel�e chaque frame pour effectuer les op�rations du composant
void UDestructionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); // Appel � la fonction de base pour l'actualisation
}

// Fonction pour effectuer le rayon de destruction
void UDestructionComponent::DestructionBeam()
{
	// Cette fonction peut �tre utilis�e pour initier ou manipuler le rayon, mais pour l'instant elle est vide
}

// Fonction pour effectuer la d�tection de l'impact du rayon
void UDestructionComponent::DestructionDetection()
{
	FHitResult hit; // Structure pour stocker les informations du rayon

	// D�finir le canal de collision utilis� pour le rayon
	ECollisionChannel channel(ECC_GameTraceChannel1);

	// Param�tres du rayon : le nom est vide, 'false' pour ne pas ignorer les collisions avec l'acteur propri�taire
	const FCollisionQueryParams traceParam(FName(TEXT("")), false, GetOwner());

	// D�finir la position de d�part du rayon (la position de la cam�ra)
	FVector startPosition = m_Camera->GetComponentLocation();

	// D�finir la direction du rayon en fonction de la direction de la cam�ra
	FVector endPosition = startPosition + m_Camera->GetForwardVector() * m_Range;

	// Effectuer le rayon dans le monde (line trace)
	if (!GetWorld()->LineTraceSingleByChannel(OUT hit, startPosition, endPosition, channel, traceParam))
	{
		// Si aucun impact n'est d�tect�, r�initialiser l'acteur destructible
		m_Destructible = nullptr;
		return;
	}

	// R�cup�rer l'acteur touch� par le rayon
	AActor* hitActor = hit.GetActor();

	// Si aucun acteur n'est touch�, r�initialiser l'acteur destructible
	if (hitActor == nullptr)
	{
		m_Destructible = nullptr;
		return;
	}

	// V�rifier si l'acteur touche impl�mente l'interface IDestructible
	if (hitActor->GetClass()->ImplementsInterface(UDestructible::StaticClass()))
	{
		// Si l'acteur est destructible, affecter l'acteur destructible et appeler sa fonction DestroyObject
		m_Destructible = hitActor;
		IDestructible::Execute_DestroyObject(m_Destructible); // Appel de la fonction de destruction sur l'acteur
	}
	else
	{
		// Si l'acteur ne supporte pas l'interface IDestructible, r�initialiser l'acteur destructible
		m_Destructible = nullptr;
	}
}
