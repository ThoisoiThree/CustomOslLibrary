#pragma once
//#include "stdosl.h"


// gives RGB value from wavelength
color getRgbSpectrum(float w_lnt, float gamma_r, float gamma_g, float gamma_b)
{   
    //spectrum things
    float r, g, b;
    if (w_lnt >= 380 && w_lnt <= 410){
        r = 0.6 - 0.41 * (410 - w_lnt)/30;
        g = 0;
        b = 0.39 + 0.6 * (410 - w_lnt)/30;
    }
    if (w_lnt >= 410 && w_lnt <= 440){
        r = 0.19 - 0.19 * (440 - w_lnt)/30;
        g = 0;
        b = 1;
    }
    if (w_lnt >= 490 && w_lnt <= 510){
        r = 0;
        g = 1;
        b = (510 - w_lnt)/20;
    }
    if (w_lnt >= 510 && w_lnt <= 580){
        r = 1 - (580 - w_lnt)/70;
        g = 1;
        b = 0;
    }
    if (w_lnt >= 580 && w_lnt <= 640){
        r = 1;
        g = (640 - w_lnt)/60;
        b = 0;
    }
    if (w_lnt >= 640 && w_lnt <= 700){
        r = 1;
        g = 0;
        b = 0;
    }
    if (w_lnt >= 700 && w_lnt <= 780){
        r = 0.35 - 0.65 * (780- w_lnt)/80;
        g = 0;
        b = 0;
    }

    //apply gamma correction
    r = pow(r, (1 / gamma_r));
    g = pow(g, (1 / gamma_g));
    b = pow(b, (1 / gamma_b));

    //output color
    color res = color (r, g, b);

  /*res[0] = r;
    res[1] = g;
    res[2] = b;*/
  
    return res;
}

// computes fresnel
float getFresnel(normal i_normal, float i_ior)
{
        float o_reflect = 0.0;
        float o_refract = 0.0;
        
        fresnel(normalize(I),i_normal,(1 / i_ior),o_reflect,o_refract);
        return o_reflect;
}

// linearise 2.2 gamma 
color linearize(color i_color)
{
    color o_color = pow(i_color, 2.2);
    return o_color;
}

