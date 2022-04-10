#include "stdosl.h"

float getFresnel(normal i_normal, float i_ior){
        float o_reflect = 0.0;
        float o_refract = 0.0;
        
        fresnel(normalize(I),i_normal,(1 / i_ior),o_reflect,o_refract);
        return o_reflect;
    }

