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

#include "AdvancedMovementPrimaryDataAsset.h"
#include"NewCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Animation/AnimMontage.h"



UAdvancedMovementPrimaryDataAsset::UAdvancedMovementPrimaryDataAsset()
{
    MontagePlayRate = 1.0f;
    MontageStartDuration = 0.0f;

    MontageBlendOutTime = 0.0f;

// Check if the lengths of both arrays are the same
#if !UE_BUILD_SHIPPING
    if (WarpTargetLocationOffsets.Num() != WarpTargetNames.Num())
    {
        // Log a warning message
        UE_LOG(LogTemp, Warning, TEXT("Warning: WarpTargetLocationOffsets and WarpTargetNames arrays do not have the same length!"));
    }
#endif
}

FVector UAdvancedMovementPrimaryDataAsset::AdjustAndUpdateWarpTarget(int32 Index, FVector CurrentWarpLocation, ACharacter* Character, FName& OutWarpTargetName) const
{
    // Ensure the Character pointer is valid
    if (!Character)
    {
        UE_LOG(LogTemp, Warning, TEXT("Character is null in AdjustAndUpdateWarpTarget"));
        OutWarpTargetName = FName(); // Return default warp target name
        return CurrentWarpLocation;  // Return the current warp location
    }

    // Check if the Index is valid for WarpTargetLocationOffsets
    if (WarpTargetLocationOffsets.IsValidIndex(Index))
    {
        // Get the forward, right, and up vectors of the character
        FVector CharForward = Character->GetActorForwardVector();
        FVector CharRight = Character->GetActorRightVector();
        FVector CharUp = Character->GetActorUpVector();

        // Get the offset for the warp target at the specified index
        FVector Offset = WarpTargetLocationOffsets[Index];

        // Calculate the new warp location using offsets for each direction
        FVector NewWarpLocation = CurrentWarpLocation + (CharForward * Offset.X) + (CharRight * Offset.Y) + (CharUp * Offset.Z);

        // Retrieve the warp target name from the WarpTargetNames array
        if (WarpTargetNames.IsValidIndex(Index))
        {
            OutWarpTargetName = WarpTargetNames[Index];
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid index for WarpTargetNames array: %d"), Index);
            OutWarpTargetName = FName(); // Set to default if the index is invalid
        }

        // Return the new warp location
        return NewWarpLocation;
    }

    // Handle invalid index appropriately
    UE_LOG(LogTemp, Warning, TEXT("Invalid index for WarpTargetLocationOffsets array: %d"), Index);
    OutWarpTargetName = FName(); // Set to empty or a default value
    return CurrentWarpLocation; // Return the current location if invalid index
}




