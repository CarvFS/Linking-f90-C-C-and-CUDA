! wrapfTutorial_tutorial.F90
! This file is generated by Shroud 0.12.2. Do not edit.
!>
!! \file wrapfTutorial_tutorial.F90
!! \brief Shroud generated wrapper for tutorial namespace
!<
! splicer begin namespace.tutorial.file_top
! splicer end namespace.tutorial.file_top
module tutorial_tutorial_mod
    use iso_c_binding, only : C_INT, C_LONG, C_NULL_PTR, C_PTR, C_SIZE_T
    ! splicer begin namespace.tutorial.module_use
    ! splicer end namespace.tutorial.module_use
    implicit none

    ! splicer begin namespace.tutorial.module_top
    ! splicer end namespace.tutorial.module_top

    ! helper ShroudTypeDefines
    ! Shroud type defines from helper ShroudTypeDefines
    integer, parameter, private :: &
        SH_TYPE_SIGNED_CHAR= 1, &
        SH_TYPE_SHORT      = 2, &
        SH_TYPE_INT        = 3, &
        SH_TYPE_LONG       = 4, &
        SH_TYPE_LONG_LONG  = 5, &
        SH_TYPE_SIZE_T     = 6, &
        SH_TYPE_UNSIGNED_SHORT      = SH_TYPE_SHORT + 100, &
        SH_TYPE_UNSIGNED_INT        = SH_TYPE_INT + 100, &
        SH_TYPE_UNSIGNED_LONG       = SH_TYPE_LONG + 100, &
        SH_TYPE_UNSIGNED_LONG_LONG  = SH_TYPE_LONG_LONG + 100, &
        SH_TYPE_INT8_T    =  7, &
        SH_TYPE_INT16_T   =  8, &
        SH_TYPE_INT32_T   =  9, &
        SH_TYPE_INT64_T   = 10, &
        SH_TYPE_UINT8_T  =  SH_TYPE_INT8_T + 100, &
        SH_TYPE_UINT16_T =  SH_TYPE_INT16_T + 100, &
        SH_TYPE_UINT32_T =  SH_TYPE_INT32_T + 100, &
        SH_TYPE_UINT64_T =  SH_TYPE_INT64_T + 100, &
        SH_TYPE_FLOAT       = 22, &
        SH_TYPE_DOUBLE      = 23, &
        SH_TYPE_LONG_DOUBLE = 24, &
        SH_TYPE_FLOAT_COMPLEX      = 25, &
        SH_TYPE_DOUBLE_COMPLEX     = 26, &
        SH_TYPE_LONG_DOUBLE_COMPLEX= 27, &
        SH_TYPE_BOOL      = 28, &
        SH_TYPE_CHAR      = 29, &
        SH_TYPE_CPTR      = 30, &
        SH_TYPE_STRUCT    = 31, &
        SH_TYPE_OTHER     = 32

    ! helper capsule_data_helper
    type, bind(C) :: TUT_SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type TUT_SHROUD_capsule_data

    ! helper array_context
    type, bind(C) :: TUT_SHROUD_array
        ! address of C++ memory
        type(TUT_SHROUD_capsule_data) :: cxx
        ! address of data in cxx
        type(C_PTR) :: base_addr = C_NULL_PTR
        ! type of element
        integer(C_INT) :: type
        ! bytes-per-item or character len of data in cxx
        integer(C_SIZE_T) :: elem_len = 0_C_SIZE_T
        ! size of data in cxx
        integer(C_SIZE_T) :: size = 0_C_SIZE_T
        ! number of dimensions
        integer(C_INT) :: rank = -1
        integer(C_LONG) :: shape(7) = 0
    end type TUT_SHROUD_array

    type class1
        type(TUT_SHROUD_capsule_data) :: cxxmem
        ! splicer begin namespace.tutorial.class.Class1.component_part
        ! splicer end namespace.tutorial.class.Class1.component_part
    contains
        procedure :: set_strings => class1_set_strings
        procedure :: printvalues => class1_printvalues
        procedure :: get_int_ptr => class1_get_int_ptr
        procedure :: get_strs2 => class1_get_strs2
        procedure :: delete => class1_delete
        procedure :: get_instance => class1_get_instance
        procedure :: set_instance => class1_set_instance
        procedure :: associated => class1_associated
        ! splicer begin namespace.tutorial.class.Class1.type_bound_procedure_part
        ! splicer end namespace.tutorial.class.Class1.type_bound_procedure_part
    end type class1

    interface operator (.eq.)
        module procedure class1_eq
    end interface

    interface operator (.ne.)
        module procedure class1_ne
    end interface

    interface

        function c_class1_new(SHT_rv) &
                result(SHT_prv) &
                bind(C, name="TUT_tutorial_Class1_new")
            use iso_c_binding, only : C_PTR
            import :: TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(OUT) :: SHT_rv
            type(C_PTR) SHT_prv
        end function c_class1_new

        subroutine c_class1_set_strings(self, names) &
                bind(C, name="TUT_tutorial_Class1_set_strings")
            use iso_c_binding, only : C_PTR
            import :: TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(IN) :: self
            type(C_PTR), intent(IN) :: names(*)
        end subroutine c_class1_set_strings

        subroutine c_class1_set_strings_bufferify(self, names, &
                SHT_names_size, SHT_names_len) &
                bind(C, name="TUT_tutorial_Class1_set_strings_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT, C_SIZE_T
            import :: TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(IN) :: self
            character(kind=C_CHAR), intent(IN) :: names(*)
            integer(C_SIZE_T), intent(IN), value :: SHT_names_size
            integer(C_INT), intent(IN), value :: SHT_names_len
        end subroutine c_class1_set_strings_bufferify

        subroutine c_class1_printvalues(self) &
                bind(C, name="TUT_tutorial_Class1_printvalues")
            import :: TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(IN) :: self
        end subroutine c_class1_printvalues

        function c_class1_get_int_ptr(self, len) &
                result(SHT_rv) &
                bind(C, name="TUT_tutorial_Class1_get_int_ptr")
            use iso_c_binding, only : C_INT, C_PTR
            import :: TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_class1_get_int_ptr

        subroutine c_class1_get_int_ptr_bufferify(self, SHT_rv) &
                bind(C, name="TUT_tutorial_Class1_get_int_ptr_bufferify")
            import :: TUT_SHROUD_array, TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(IN) :: self
            type(TUT_SHROUD_array), intent(OUT) :: SHT_rv
        end subroutine c_class1_get_int_ptr_bufferify

        subroutine c_class1_get_strs2(self, strs, name_len) &
                bind(C, name="TUT_tutorial_Class1_get_strs2")
            use iso_c_binding, only : C_INT, C_PTR
            import :: TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(IN) :: self
            type(C_PTR), intent(OUT) :: strs
            integer(C_INT), intent(OUT) :: name_len
        end subroutine c_class1_get_strs2

        subroutine c_class1_get_strs2_bufferify(self, SHT_strs_cdesc) &
                bind(C, name="TUT_tutorial_Class1_get_strs2_bufferify")
            import :: TUT_SHROUD_array, TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(IN) :: self
            type(TUT_SHROUD_array), intent(OUT) :: SHT_strs_cdesc
        end subroutine c_class1_get_strs2_bufferify

        subroutine c_class1_delete(self) &
                bind(C, name="TUT_tutorial_Class1_delete")
            import :: TUT_SHROUD_capsule_data
            implicit none
            type(TUT_SHROUD_capsule_data), intent(INOUT) :: self
        end subroutine c_class1_delete

        ! splicer begin namespace.tutorial.class.Class1.additional_interfaces
        ! splicer end namespace.tutorial.class.Class1.additional_interfaces

        ! splicer begin namespace.tutorial.additional_interfaces
        ! splicer end namespace.tutorial.additional_interfaces
    end interface

    interface class1
        module procedure class1_new
    end interface class1

contains

    function class1_new() &
            result(SHT_rv)
        use iso_c_binding, only : C_PTR
        type(class1) :: SHT_rv
        type(C_PTR) :: SHT_prv
        ! splicer begin namespace.tutorial.class.Class1.method.new
        SHT_prv = c_class1_new(SHT_rv%cxxmem)
        ! splicer end namespace.tutorial.class.Class1.method.new
    end function class1_new

    subroutine class1_set_strings(obj, names)
        use iso_c_binding, only : C_INT, C_SIZE_T
        class(class1) :: obj
        character(len=*), intent(IN) :: names(:)
        ! splicer begin namespace.tutorial.class.Class1.method.set_strings
        call c_class1_set_strings_bufferify(obj%cxxmem, names, &
            size(names, kind=C_SIZE_T), len(names, kind=C_INT))
        ! splicer end namespace.tutorial.class.Class1.method.set_strings
    end subroutine class1_set_strings

    subroutine class1_printvalues(obj)
        class(class1) :: obj
        ! splicer begin namespace.tutorial.class.Class1.method.printvalues
        call c_class1_printvalues(obj%cxxmem)
        ! splicer end namespace.tutorial.class.Class1.method.printvalues
    end subroutine class1_printvalues

    function class1_get_int_ptr(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, c_f_pointer
        class(class1) :: obj
        integer(C_INT), pointer :: SHT_rv(:)
        ! splicer begin namespace.tutorial.class.Class1.method.get_int_ptr
        type(TUT_SHROUD_array) :: SHT_rv_cdesc
        call c_class1_get_int_ptr_bufferify(obj%cxxmem, SHT_rv_cdesc)
        call c_f_pointer(SHT_rv_cdesc%base_addr, SHT_rv, &
            SHT_rv_cdesc%shape(1:1))
        ! splicer end namespace.tutorial.class.Class1.method.get_int_ptr
    end function class1_get_int_ptr

    subroutine class1_get_strs2(obj, strs)
        use iso_c_binding, only : C_LOC
        class(class1) :: obj
        character(*), intent(OUT), target :: strs(:)
        ! splicer begin namespace.tutorial.class.Class1.method.get_strs2
        type(TUT_SHROUD_array) :: SHT_strs_cdesc
        SHT_strs_cdesc%cxx%addr = C_LOC(strs)
        SHT_strs_cdesc%base_addr = C_LOC(strs)
        SHT_strs_cdesc%type = SH_TYPE_CHAR
        SHT_strs_cdesc%elem_len = len(strs)
        SHT_strs_cdesc%size = size(strs)
        SHT_strs_cdesc%rank = rank(strs)
        SHT_strs_cdesc%shape(1:1) = shape(strs)
        call c_class1_get_strs2_bufferify(obj%cxxmem, SHT_strs_cdesc)
        ! splicer end namespace.tutorial.class.Class1.method.get_strs2
    end subroutine class1_get_strs2

    subroutine class1_delete(obj)
        class(class1) :: obj
        ! splicer begin namespace.tutorial.class.Class1.method.delete
        call c_class1_delete(obj%cxxmem)
        ! splicer end namespace.tutorial.class.Class1.method.delete
    end subroutine class1_delete

    ! Return pointer to C++ memory.
    function class1_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(class1), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function class1_get_instance

    subroutine class1_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(class1), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine class1_set_instance

    function class1_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(class1), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function class1_associated

    ! splicer begin namespace.tutorial.class.Class1.additional_functions
    ! splicer end namespace.tutorial.class.Class1.additional_functions

    ! splicer begin namespace.tutorial.additional_functions
    ! splicer end namespace.tutorial.additional_functions

    function class1_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_eq

    function class1_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_ne

end module tutorial_tutorial_mod
