.PHONY: clean All

All:
	@echo "----------Building project:[ STL_Challenge4 - Debug ]----------"
	@cd "STL_Challenge4" && "$(MAKE)" -f  "STL_Challenge4.mk"
clean:
	@echo "----------Cleaning project:[ STL_Challenge4 - Debug ]----------"
	@cd "STL_Challenge4" && "$(MAKE)" -f  "STL_Challenge4.mk" clean
