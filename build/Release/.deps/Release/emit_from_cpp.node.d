cmd_Release/emit_from_cpp.node := ln -f "Release/obj.target/emit_from_cpp.node" "Release/emit_from_cpp.node" 2>/dev/null || (rm -rf "Release/emit_from_cpp.node" && cp -af "Release/obj.target/emit_from_cpp.node" "Release/emit_from_cpp.node")
