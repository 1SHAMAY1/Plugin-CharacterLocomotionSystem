/**
 * Copyright (c) 2024 [SHANKHARAJ DATTA]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software, known as the "Soft Character Locomotion System," and associated
 * documentation files (including user manuals, API documentation, and readme files)
 * (the "Software"), to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * EXCEPTION: The animations included with this Software (if any) are not covered
 * under this license and may not be used, copied, modified, merged, published,
 * distributed, sublicensed, or sold without express permission from [SHANKHARAJ DATTA].
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AdvancedMovementPrimaryDataAsset.generated.h"

class UAnimMontage;

/**
 * UAdvancedMovementPrimaryDataAsset
 * 
 * This class serves as a base data asset for advanced movement mechanics 
 * within the new character movement component. It is intended to be extended 
 * by child classes such as vaulting, mantling, and climbing up, 
 * allowing for a modular approach to managing movement-related data.
 */
UCLASS(BlueprintType)
class CHARACTERLOCOMOTIONSYSTEM_API UAdvancedMovementPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UAdvancedMovementPrimaryDataAsset();

	// Array of location offsets for warp targets, which represent relative positions to adjust the character's movement destination during advanced actions.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement:Advanced")
	TArray<FVector> WarpTargetLocationOffsets;

	// Array containing the names of warp targets, used to identify specific warp locations during advanced movement sequences.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement:Advanced")
	TArray<FName> WarpTargetNames;

	// Reference to an animation montage that will be played during advanced movement actions, such as dashing or vaulting.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement:Advanced")
	UAnimMontage* AdvancedMovementMontage;

	// Duration of the blend-in time when starting the advanced movement montage, defining how smoothly the montage starts.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement:Advanced")
	float MontageStartDuration;

	// Playback speed for the advanced movement montage, controlling the rate at which the animation plays. A higher value means a faster playback.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement:Advanced")
	float MontagePlayRate;

	// Duration for blending out of the advanced movement montage when it finishes, ensuring a smooth transition back to normal movement.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement:Advanced")
	float MontageBlendOutTime;

	/**
	 * Adjusts and updates the warp target location based on the specified index.
	 * This function returns a modified location for the warp target and also
	 * provides the corresponding warp target name via the output parameter.
	 * It can be used to fine-tune movement during gameplay, such as adjusting the
	 * final landing spot of a dash or vault.
	 *
	 * @param Index - The index of the warp target to adjust.
	 * @param CurrentWarpLocation - The current location to be adjusted.
	 * @param Character - The character performing the movement.
	 * @param OutWarpTargetName - The output parameter that returns the name of the warp target.
	 * @return The modified warp target location.
	 */
	UFUNCTION(BlueprintPure, Category = "Movement:Advanced")
	FVector AdjustAndUpdateWarpTarget(int32 Index, FVector CurrentWarpLocation, ACharacter* Character, FName& OutWarpTargetName) const;



};
