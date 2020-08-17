.name           "42"
.comment        "Just a basic Winner Program"

l2:	sti	r1,%:451645,%0
	and	r1,%456456,r1
live:	live	%1
	zjmp	%:live
