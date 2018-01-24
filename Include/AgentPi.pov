#include "colors.inc"
#include "shapes.inc" 
    
#declare w = 1; //width
#declare h = 4; //height 
#declare d = -2; //depth
#declare proportion = 1;  

#declare c = <0,0,0>;
        
camera{


    location <5,6,1>
    look_at <0,3,1>
    rotate<10*clock,-90*clock,0> 
    translate<0,-.4*clock,0>

}  
light_source { 
        <-1,4.5,3>
        color White 
}
light_source { 
        <-1,4.5,-3>
        color White 
}
 

background{Blue}
 union{
//Body
    
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(<0,0,0>,<-w,-h,-d>, 0.25   , 0)  
             
            texture{ pigment{ color Cyan}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate<0,5,0>
          } // ---------------------------------------------------------
          
    
    //ArmR      
    union{
    
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.5,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
               scale<1,1,1>*proportion  rotate<0, 0,0> translate<0,0,0> 
              } // ---------------------------------------------------------
              
        //HandR      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>,<0.6,0,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
              scale<1,1,1>*proportion  rotate<0, 0,0> translate<-0.7,0,0>
              } // ---------------------------------------------------------
        scale<1,1,1>*proportion  rotate<90,0,0> translate c+<-0.3,3,3.4>      
    }  
    
    
    //ArmL      
    union{
    
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.5,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
               scale<1,1,1>*proportion  rotate<0, 0,0> translate<0,0,0> 
              } // ---------------------------------------------------------
              
        //HandL      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>,<0.6,0,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
              scale<1,1,1>*proportion  rotate<0, 0,0> translate<-0.7,0,0>
              } // ---------------------------------------------------------
        scale<1,1,1>*proportion  rotate<-90,0,0> translate c+<-0.3,3.4,-1.4>      
    }
    
    
    
     //LegR      
    union{
    
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.5,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
               scale<1,1,1>*proportion  rotate<0, 0,0> translate<0,0,0> 
              } // ---------------------------------------------------------
              
        //FeetR      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>,<0.6,0,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
              scale<1,1,1>*proportion  rotate<0, 0,0> translate<-0.7,0,0>
              } // ---------------------------------------------------------
        scale<1,1,1>*proportion  rotate<180,0,0> translate c+<-0.5,0,1.2>      
    }  
    
    
         //LegR      
    union{
    
        object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>, <-0.3,-1.5,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
               scale<1,1,1>*proportion  rotate<0, 0,0> translate<0,0,0> 
              } // ---------------------------------------------------------
              
        //FeetR      
         object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<0,0,0>,<0.6,0,-0.5>, 0.1   , 0)  
                 
                texture{ pigment{ color Cyan}
                       //normal { radial sine_wave frequency 30 scale 0.25 }
                         finish { phong 1 }
                        }
              scale<1,1,1>*proportion  rotate<0, 0,0> translate<-0.7,0,0>
              } // ---------------------------------------------------------
        scale<1,1,1>*proportion  rotate<180,0,0> translate c+<-0.5,0,0.2>       
               
          
        }
    //Left eye
    union{
        sphere { <0,0,0>, 0.3 
        
                texture { pigment{ color White}
                          finish { phong 1.0 reflection 0.00}
                        } // end of texture
        
                  scale<1,1,1>*proportion  rotate<0,0,0>  translate <0,0,0> 
               }  // end of sphere -----------------------------------
               //Iris1
                    sphere { c, 0.1 
                    
                            texture { pigment{ color Black}
                                      finish { phong 1.0 reflection 0.00}
                                    } // end of texture
                    
                              scale<1,1,1>*proportion  rotate<0,0,0>  translate c+<-0.3,0,0>  
                           }  // end of sphere -----------------------------------  
                    scale<1,1,1>*proportion  rotate<0,0,0>  translate c +<-0.85,4,0.55>     
                    }                       
                       
                       
                       
    //Rigth eye
       union{
        sphere { <0,0,0>, 0.3 
        
                texture { pigment{ color White}
                          finish { phong 1.0 reflection 0.00}
                        } // end of texture
        
                  scale<1,1,1>*proportion  rotate<0,0,0>  translate <0,0,0> 
               }  // end of sphere -----------------------------------
               //Iris1
                    sphere { c, 0.1 
                    
                            texture { pigment{ color Black}
                                      finish { phong 1.0 reflection 0.00}
                                    } // end of texture
                    
                              scale<1,1,1>*proportion  rotate<0,0,0>  translate c+<-0.3,0,0>  
                           }  // end of sphere -----------------------------------  
                    scale<1,1,1>*proportion  rotate<0,0,0>  translate c +<-0.85,4,1.4>     
                    }                       
                       
               
    // CejaRigth
    
    cylinder { c+<0,4,0>,c+<0,4,0.55>, 0.08
               texture { pigment { color Black}
                       //normal  { bumps 0.5 scale <0.25, 0.005,0.005>}  
                         finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture
               scale <1,1,1>*proportion rotate<-16,0,0> translate<-1,0.5,2.2>
             } // end of cylinder  ------------------------------------
    
    
    
           
    // CejaLeft
    
     cylinder { c+<0,4,0>,c+<0,4,0.55>, 0.08
               texture { pigment { color Black}
                       //normal  { bumps 0.5 scale <0.25, 0.005,0.005>}  
                         finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture
               scale <1,1,1>*proportion rotate<16,0,0> translate<-1,0.65,-0.8>
             } // end of cylinder  ------------------------------------
    
    
           
    // Pico
    
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(c+<0.2,0,-0.6>,c+<-0.7,0.2,-1.4>, 0.1   , 0)  
             
            texture{ pigment{ color Orange}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate<-0.9,3.5,2>
          } // ---------------------------------------------------------
    
    //Nose            
    triangle { 
                    c+<-0.01, 0, -0.75>, c+<-0.01, 0, -1.25>, c+<-0.01, 0.5, -1>
                    texture { pigment{ color Orange } 
                    finish { phong 1.0 }
                  }
                  scale<1,1,1>*proportion rotate<0, 0,0> translate<-1,3.5,2>
                   }
                   
                   
    //Cola 
    
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box( <0,0,0>,<2,-0.3,-1.2>, 0.1   , 0)  
             
            texture{ pigment{ color Red}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate<0,2,1.65>
          } // ---------------------------------------------------------
          
    //Hat
 union{   
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(c+<-0.4,0,-1.2>,c+<1,0.2,1>, 0.1   , 0)  
                                  
            texture{ pigment{ color SemiSweetChoc}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }                           
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate<0.1,3.9,-0.9>
          } // --------------------------------------------------------- 
          
    //Hat
    
    object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(c+<-0.6,0,-1>,c+<0.5,0.6,0.8>, 0.1   , 0)  
                                  
            texture{ pigment{ color SemiSweetChoc}
                   //normal { radial sine_wave frequency 30 scale 0.25 }
                     finish { phong 1 }                           
                    }
            scale<1,1,1>*proportion  rotate<0, 0,0> translate<0.48,4,-0.87>
          } // ---------------------------------------------------------
         scale<1,1,1>*proportion  rotate<0, 0,0> translate<-1,0.8,2>   
 }                   
 scale<1,1,1>*proportion  rotate<0, 0,0> translate<0,2,0>   

}








