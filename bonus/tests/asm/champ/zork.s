    .name "zork"
    .comment "I'M ALIIIIVE"
l2:		sti r1, %:live, %2
		and r1, %3, r1

live:	live %1
		zjmp %:live
