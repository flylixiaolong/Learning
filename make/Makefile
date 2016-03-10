str:=$(shell pwd)
source:="hello test make help"
reserse=$(2) $(1)
all:
	echo $(dir $(str))
	@echo $(str)
	@echo $(foreach var,$(source),$(var).c) 
	$(if word(1,$(source)),@echo "find",@echo "not found")
	@echo $(call reserse,a,b)
