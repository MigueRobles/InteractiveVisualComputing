#ifndef(Cage_Inc_Temp)
#declare Cage_Inc_Temp=version;
#version 3.6

#macro Cage() 

    union{
        #declare cage_corner1 = <0,0,0>;
        #declare cage_corner2 = <10,18,8>;
        #declare cage_radius = 0.4;
        difference{
        
            box{
                cage_corner1, cage_corner2
                texture { pigment{Black} //  blueish green
                        // normal { bumps 0.5 scale 0.05 }
                        finish { phong 1 reflection 0.00}
                 } // end of texture 
            
            }
            
            box{
                 cage_corner1+<0.4,-0.4,-0.4>, cage_corner2+<-0.4,-0.4,-0.4>
                 texture { pigment{Black} //  blueish green
                        // normal { bumps 0.5 scale 0.05 }
                        finish { phong 1 reflection 0.00}
                 } // end of texture 
            }
        
        }
        
        #for (i, 0.6, 10, 1)
            cylinder{
                cage_corner1+<i,0,0>
                cage_corner1+<i, 17.8,0>
                0.2
                texture{
                    pigment{color Grey}
                }
            }
        
        #end
        scale<0,1,0>   
    }
#end//End del macro 
#end