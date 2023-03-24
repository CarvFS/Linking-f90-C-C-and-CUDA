program rism1d_main

  use rism1d_mod
  
  type(rism1d) :: r1d
  
  call calling(r1d)
  
  write(*,*) "extra_precision = ", r1d%extra_precision
  write(*,*) "Mdiis_vec = ", r1d%Mdiis_vec, "mdiis_method = ", r1d%mdiis_method
  write(*,*) "savefile = ", r1d%savefile, " closureID = ", r1d%closureID
  
  write(*,*) "rism1d_getInvDebyeLen", rism1d_getInvDebyeLen(r1d)
  
end program rism1d_main
