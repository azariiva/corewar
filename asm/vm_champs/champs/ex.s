.name "kakaha"
.comment "just a basic living prog"

l2:	sti	r1,%:451645,%-10
	and	r1,%456456,r1
live:	live	%1
	zjmp	%:live
