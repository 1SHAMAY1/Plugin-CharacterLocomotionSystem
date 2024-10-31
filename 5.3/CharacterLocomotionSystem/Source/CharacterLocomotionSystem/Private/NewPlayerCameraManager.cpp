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

#include "NewPlayerCameraManager.h"
#include "NewCharacter.h"
#include "NewCharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

ANewPlayerCameraManager::ANewPlayerCameraManager()
{
    SmoothBlendDuration = 0.2f;
    SmoothBlendTime = 0.0f;

}

void ANewPlayerCameraManager::UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime)
{
    Super::UpdateViewTarget(OutVT, DeltaTime);

    if (ANewCharacter* NewCharacter = Cast<ANewCharacter>(GetOwningPlayerController()->GetPawn()))
    {
        UNewCharacterMovementComponent* NMC = NewCharacter->GetNewCharacterMovementComponent();
        float DefaultCapsuleHalfHeight = NewCharacter->GetClass()->GetDefaultObject<ACharacter>()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

        // Determine the current target offset based on the character's state
        float TargetHalfHeight = DefaultCapsuleHalfHeight;

        if (NMC->IsCrouching())
        {
            TargetHalfHeight = NMC->GetCrouchedHalfHeight();
        }
        else if (NMC->IsProning())
        {
            TargetHalfHeight = NMC->GetProneHalfHeight();
        }
        else if (NMC->IsSliding())
        {
            TargetHalfHeight = NMC->GetSlideHalfHeight();
        }
        else if (NMC->IsVaulting())
        {
            TargetHalfHeight = NMC->GetVaultHalfHeight();
        }
        else
        {
            TargetHalfHeight = (NMC->GetCrouchedHalfHeight() + NMC->GetProneHalfHeight() + NMC->GetSlideHalfHeight() + NMC->GetVaultHalfHeight()) / 4;
        }

        // Calculate the target offset based on the difference from the default half-height
        FVector CurrentTargetOffset = FVector(0, 0, TargetHalfHeight - DefaultCapsuleHalfHeight);

        // Calculate the final offset and apply it
        FVector Offset = FMath::Lerp(FVector::ZeroVector, CurrentTargetOffset, FMath::Clamp(SmoothBlendTime / SmoothBlendDuration, 0.f, 1.f));

        // Smoothly blend the offset
        if (NMC->IsCrouching() || NMC->IsProning() || NMC->IsSliding() || NMC->IsVaulting())
        {
            SmoothBlendTime = FMath::Clamp(SmoothBlendTime + DeltaTime, 0.f, SmoothBlendDuration);
            Offset -= CurrentTargetOffset;
        }
        else
        {
            SmoothBlendTime = FMath::Clamp(SmoothBlendTime - DeltaTime, 0.f, SmoothBlendDuration);
        }
        OutVT.POV.Location += Offset;
    }
}






