ksp-physics.pdf: ksp-physics.tex
	latexmk -pdf ksp-physics.tex; latexmk -c ksp-physics.tex
