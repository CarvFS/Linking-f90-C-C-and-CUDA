! splicer begin namespace.tutorial.class.Class1.method.get_strs
type(C_PTR) cstr
cstr = C_LOC(strs)
call c_class1_get_strs_bufferify(obj%cxxmem, cstr, name_len)
call C_F_POINTER(cstr,strs,[2])
print*,strs(1),strs(2),name_len
! splicer end namespace.tutorial.class.Class1.method.get_strs