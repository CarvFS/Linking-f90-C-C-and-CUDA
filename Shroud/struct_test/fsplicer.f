! splicer begin namespace.tutorial.class.Class1.method.get_name2
type(C_PTR) names_Cptr
names_Cptr = C_LOC(names)
call c_class1_get_name2_bufferify(obj%cxxmem, names_Cptr, name_len)
call C_F_POINTER(names_Cptr,names,[name_len])
! splicer end namespace.tutorial.class.Class1.method.get_name2