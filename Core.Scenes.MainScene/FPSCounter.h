#pragma once


namespace Forradica
{


        namespace FPSCounter
        {
                void Update();
                void Render();

                inline int tickLastUpdate = 0;
                inline int framesCount = 0;
                inline int fps = 0;
        };



}
