program rism1d_main
  use iso_c_binding
  use rism1d_mod
  implicit none
  
  type(rism1d) :: r1d
  type(solvMDL) :: mdl
  type(mdiis) :: mdiis_o

  character(256, C_char) :: o_form = "PR"//char(0)
  character(256, C_char) :: filename = "name of the file"//char(0)
  character(256, C_char) :: nbfix = "nbfix_me"//char(0)

  real(C_double) :: xvv_o(3,3,3)
  !real(C_double) :: xvv_o(5)
  double precision :: residual
  double precision :: tolerance
  logical(C_bool) :: start,converged,o_all

  integer :: i,j,k,ndim
  ndim = 3
  do i=1,ndim
    do j=1,ndim
      do k=1,ndim
        xvv_o(i,j,k) = 1.23+i+k+j
      end do
    end do
  end do

  call calling(r1d)
  
  write(*,*) "extra_precision = ", r1d%extra_precision
  !write(*,*) "Mdiis_vec = ", r1d%Mdiis_vec, "mdiis_method = ", r1d%mdiis_method
  !write(*,*) "savefile = ", r1d%savefile, " closureID = ", r1d%closureID
  
  write(*,*) "rism1d_getInvDebyeLen", rism1d_getInvDebyeLen(r1d)
  write(*,*)
  write(*,*) "rism1d_getCompressibility", rism1d_getCompressibility(r1d)
  write(*,*)
  write(*,*) "rism1d_getCompressibility_dT", rism1d_getCompressibility_dT(r1d)
  write(*,*)
  write(*,*) "rism1d_get3DRISMbackground", rism1d_get3DRISMbackground(r1d)
  write(*,*)
  write(*,*) "rism1d_getDelHvLimit", rism1d_getDelHvLimit(r1d)
  write(*,*)
  write(*,*) "rism1d_getDelHvLimit_dt", rism1d_getDelHvLimit_dT(r1d)
  write(*,*)
  write(*,*) "rism1d_getSusceptibility", rism1d_getSusceptibility(r1d)
  write(*,*)
  write(*,*) "rism1d_getSusceptibility_dT", rism1d_getSusceptibility_dT(r1d)
  write(*,*)
  write(*,*) "rism1d_getExNumber", rism1d_getExNumber(r1d)
  write(*,*)
  write(*,*) "rism1d_getStructFactor", rism1d_getStructFactor(r1d)
  write(*,*)
  write(*,*) "rism1d_getRunExNumber", rism1d_getRunExNumber(r1d)
  write(*,*)
  write(*,*) "rism1d_getExChem", rism1d_getExChem(r1d, o_form)
  write(*,*)

  write(*,*) "rism1d_addSpecies"
  call rism1d_addSpecies(r1d, mdl, 123)
  write(*,*)

  write(*,*) "rism1d_solve3DRISM_dT"
  write(*,*) rism1d_solve3DRISM_dT(r1d, -1, 2, 10000, 1d-4)
  write(*,*)

  write(*,*) "rism1d_single3DRISMsolution_dT"
  residual = 1.2
  tolerance = 1d-4
  start = .TRUE.
  converged = .FALSE.
  do i=1,ndim
    do j=1,ndim
     do k=1,ndim
      write(*,*) "(", i,j,k, ")", xvv_o(i,j,k)
      end do
    end do
  end do
  call rism1d_single3DRISMsolution_dT(r1d,xvv_o,residual,tolerance,start,converged,mdiis_o)
  write(*,*)

  write(*,*) "rism1d_selftest"
  o_all = .TRUE.
  call rism1d_selftest(r1d,filename,o_all)
  write(*,*)

  write(*,*) "rism1d_readNBFix"
  call rism1d_readNBFix(r1d,nbfix)
  write(*,*)


end program rism1d_main
