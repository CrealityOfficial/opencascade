if(CC_INSTALL_OPENCASCADE)
	__install_directory_specif(${CMAKE_CURRENT_SOURCE_DIR}/install/include/ opencascade)
	
	set(LIBS)
	set(DLLS)
	
					
	set(LIB_WIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/install/x64/)
	if(CMAKE_BUILD_TYPE MATCHES "Release")
		if(CC_BC_WIN)
			
			set( LIBS ${LIB_WIN_ROOT}/lib/TKBin.lib
					  ${LIB_WIN_ROOT}/lib/TKBinL.lib
					  ${LIB_WIN_ROOT}/lib/TKBinXCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKBO.lib
					  ${LIB_WIN_ROOT}/lib/TKBool.lib
					  ${LIB_WIN_ROOT}/lib/TKBRep.lib
					  ${LIB_WIN_ROOT}/lib/TKCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKCDF.lib
					  ${LIB_WIN_ROOT}/lib/TKernel.lib
					  ${LIB_WIN_ROOT}/lib/TKG2d.lib
					  ${LIB_WIN_ROOT}/lib/TKG3d.lib
					  ${LIB_WIN_ROOT}/lib/TKGeomAlgo.lib
					  ${LIB_WIN_ROOT}/lib/TKGeomBase.lib
					  ${LIB_WIN_ROOT}/lib/TKHLR.lib
					  ${LIB_WIN_ROOT}/lib/TKIGES.lib
					  ${LIB_WIN_ROOT}/lib/TKLCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKMath.lib
					  ${LIB_WIN_ROOT}/lib/TKMesh.lib
					  ${LIB_WIN_ROOT}/lib/TKPrim.lib
					  ${LIB_WIN_ROOT}/lib/TKRWMesh.lib
					  ${LIB_WIN_ROOT}/lib/TKService.lib
					  ${LIB_WIN_ROOT}/lib/TKShHealing.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEP.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEP209.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEPAttr.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEPBase.lib
					  ${LIB_WIN_ROOT}/lib/TKSTL.lib
					  ${LIB_WIN_ROOT}/lib/TKTopAlgo.lib
					  ${LIB_WIN_ROOT}/lib/TKV3d.lib
					  ${LIB_WIN_ROOT}/lib/TKVCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKVRML.lib
					  ${LIB_WIN_ROOT}/lib/TKXCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKXDEIGES.lib
					  ${LIB_WIN_ROOT}/lib/TKXDESTEP.lib
					  ${LIB_WIN_ROOT}/lib/TKXml.lib
					  ${LIB_WIN_ROOT}/lib/TKXmlL.lib
					  ${LIB_WIN_ROOT}/lib/TKXmlXCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKXSBase.lib


			)
			
			set (DLLS 	${LIB_WIN_ROOT}/bin/TKBin.dll
						${LIB_WIN_ROOT}/bin/TKBinL.dll
						${LIB_WIN_ROOT}/bin/TKBinXCAF.dll
						${LIB_WIN_ROOT}/bin/TKBO.dll
						${LIB_WIN_ROOT}/bin/TKBool.dll
						${LIB_WIN_ROOT}/bin/TKBRep.dll
						${LIB_WIN_ROOT}/bin/TKCAF.dll
						${LIB_WIN_ROOT}/bin/TKCDF.dll
						${LIB_WIN_ROOT}/bin/TKernel.dll
						${LIB_WIN_ROOT}/bin/TKG2d.dll
						${LIB_WIN_ROOT}/bin/TKG3d.dll
						${LIB_WIN_ROOT}/bin/TKGeomAlgo.dll
						${LIB_WIN_ROOT}/bin/TKGeomBase.dll
						${LIB_WIN_ROOT}/bin/TKHLR.dll
						${LIB_WIN_ROOT}/bin/TKIGES.dll
						${LIB_WIN_ROOT}/bin/TKLCAF.dll
						${LIB_WIN_ROOT}/bin/TKMath.dll
						${LIB_WIN_ROOT}/bin/TKMesh.dll
						${LIB_WIN_ROOT}/bin/TKPrim.dll
						${LIB_WIN_ROOT}/bin/TKRWMesh.dll
						${LIB_WIN_ROOT}/bin/TKService.dll
						${LIB_WIN_ROOT}/bin/TKShHealing.dll
						${LIB_WIN_ROOT}/bin/TKSTEP.dll
						${LIB_WIN_ROOT}/bin/TKSTEP209.dll
						${LIB_WIN_ROOT}/bin/TKSTEPAttr.dll
						${LIB_WIN_ROOT}/bin/TKSTEPBase.dll
						${LIB_WIN_ROOT}/bin/TKSTL.dll
						${LIB_WIN_ROOT}/bin/TKTopAlgo.dll
						${LIB_WIN_ROOT}/bin/TKV3d.dll
						${LIB_WIN_ROOT}/bin/TKVCAF.dll
						${LIB_WIN_ROOT}/bin/TKVRML.dll
						${LIB_WIN_ROOT}/bin/TKXCAF.dll
						${LIB_WIN_ROOT}/bin/TKXDEIGES.dll
						${LIB_WIN_ROOT}/bin/TKXDESTEP.dll
						${LIB_WIN_ROOT}/bin/TKXml.dll
						${LIB_WIN_ROOT}/bin/TKXmlL.dll
						${LIB_WIN_ROOT}/bin/TKXmlXCAF.dll
						${LIB_WIN_ROOT}/bin/TKXSBase.dll

						

				)     
			
		elseif(CC_BC_LINUX)
			set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/install/linux/lib/xxx.so

					)	
		else()
		endif()
	else()
		if(CC_BC_WIN)
			set( LIBS ${LIB_WIN_ROOT}/lib/TKBin.lib
					  ${LIB_WIN_ROOT}/lib/TKBinL.lib
					  ${LIB_WIN_ROOT}/lib/TKBinXCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKBO.lib
					  ${LIB_WIN_ROOT}/lib/TKBool.lib
					  ${LIB_WIN_ROOT}/lib/TKBRep.lib
					  ${LIB_WIN_ROOT}/lib/TKCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKCDF.lib
					  ${LIB_WIN_ROOT}/lib/TKernel.lib
					  ${LIB_WIN_ROOT}/lib/TKG2d.lib
					  ${LIB_WIN_ROOT}/lib/TKG3d.lib
					  ${LIB_WIN_ROOT}/lib/TKGeomAlgo.lib
					  ${LIB_WIN_ROOT}/lib/TKGeomBase.lib
					  ${LIB_WIN_ROOT}/lib/TKHLR.lib
					  ${LIB_WIN_ROOT}/lib/TKIGES.lib
					  ${LIB_WIN_ROOT}/lib/TKLCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKMath.lib
					  ${LIB_WIN_ROOT}/lib/TKMesh.lib
					  ${LIB_WIN_ROOT}/lib/TKPrim.lib
					  ${LIB_WIN_ROOT}/lib/TKRWMesh.lib
					  ${LIB_WIN_ROOT}/lib/TKService.lib
					  ${LIB_WIN_ROOT}/lib/TKShHealing.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEP.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEP209.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEPAttr.lib
					  ${LIB_WIN_ROOT}/lib/TKSTEPBase.lib
					  ${LIB_WIN_ROOT}/lib/TKSTL.lib
					  ${LIB_WIN_ROOT}/lib/TKTopAlgo.lib
					  ${LIB_WIN_ROOT}/lib/TKV3d.lib
					  ${LIB_WIN_ROOT}/lib/TKVCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKVRML.lib
					  ${LIB_WIN_ROOT}/lib/TKXCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKXDEIGES.lib
					  ${LIB_WIN_ROOT}/lib/TKXDESTEP.lib
					  ${LIB_WIN_ROOT}/lib/TKXml.lib
					  ${LIB_WIN_ROOT}/lib/TKXmlL.lib
					  ${LIB_WIN_ROOT}/lib/TKXmlXCAF.lib
					  ${LIB_WIN_ROOT}/lib/TKXSBase.lib


			)
			
			set (DLLS 	${LIB_WIN_ROOT}/bin/TKBin.dll
						${LIB_WIN_ROOT}/bin/TKBinL.dll
						${LIB_WIN_ROOT}/bin/TKBinXCAF.dll
						${LIB_WIN_ROOT}/bin/TKBO.dll
						${LIB_WIN_ROOT}/bin/TKBool.dll
						${LIB_WIN_ROOT}/bin/TKBRep.dll
						${LIB_WIN_ROOT}/bin/TKCAF.dll
						${LIB_WIN_ROOT}/bin/TKCDF.dll
						${LIB_WIN_ROOT}/bin/TKernel.dll
						${LIB_WIN_ROOT}/bin/TKG2d.dll
						${LIB_WIN_ROOT}/bin/TKG3d.dll
						${LIB_WIN_ROOT}/bin/TKGeomAlgo.dll
						${LIB_WIN_ROOT}/bin/TKGeomBase.dll
						${LIB_WIN_ROOT}/bin/TKHLR.dll
						${LIB_WIN_ROOT}/bin/TKIGES.dll
						${LIB_WIN_ROOT}/bin/TKLCAF.dll
						${LIB_WIN_ROOT}/bin/TKMath.dll
						${LIB_WIN_ROOT}/bin/TKMesh.dll
						${LIB_WIN_ROOT}/bin/TKPrim.dll
						${LIB_WIN_ROOT}/bin/TKRWMesh.dll
						${LIB_WIN_ROOT}/bin/TKService.dll
						${LIB_WIN_ROOT}/bin/TKShHealing.dll
						${LIB_WIN_ROOT}/bin/TKSTEP.dll
						${LIB_WIN_ROOT}/bin/TKSTEP209.dll
						${LIB_WIN_ROOT}/bin/TKSTEPAttr.dll
						${LIB_WIN_ROOT}/bin/TKSTEPBase.dll
						${LIB_WIN_ROOT}/bin/TKSTL.dll
						${LIB_WIN_ROOT}/bin/TKTopAlgo.dll
						${LIB_WIN_ROOT}/bin/TKV3d.dll
						${LIB_WIN_ROOT}/bin/TKVCAF.dll
						${LIB_WIN_ROOT}/bin/TKVRML.dll
						${LIB_WIN_ROOT}/bin/TKXCAF.dll
						${LIB_WIN_ROOT}/bin/TKXDEIGES.dll
						${LIB_WIN_ROOT}/bin/TKXDESTEP.dll
						${LIB_WIN_ROOT}/bin/TKXml.dll
						${LIB_WIN_ROOT}/bin/TKXmlL.dll
						${LIB_WIN_ROOT}/bin/TKXmlXCAF.dll
						${LIB_WIN_ROOT}/bin/TKXSBase.dll

						

				)     

		elseif(CC_BC_LINUX)
			set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/install/linux/lib/xxx.so
					)	
		else()
		endif()
	endif()
	
	INSTALL(FILES ${LIBS} DESTINATION lib)
	INSTALL(FILES ${DLLS} DESTINATION bin)

endif()