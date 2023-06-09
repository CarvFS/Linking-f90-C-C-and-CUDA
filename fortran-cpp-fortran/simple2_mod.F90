module simple2_mod
    implicit none
    TYPE :: SIMPLEF
      INTEGER :: a
      REAL :: dk
      character,  dimension(256) :: Fstr
      ! Note that given the problem description, the component B 
      ! appears to have value semantics.  If so, as of Fortran 2003 
      ! this should be an ALLOCATABLE component.  Because it is 
      ! a pointer component, we will default initialize it to 
      ! help avoid its pointer association status becoming 
      ! inadvertently undefined 
      INTEGER, POINTER :: B(:) => NULL()
      integer, pointer :: C(:,:) => NULL()
    END TYPE SIMPLEF
end module
