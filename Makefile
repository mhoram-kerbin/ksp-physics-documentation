documentation.pdf: documentation.tex
	latexmk -pdf documentation.tex; latexmk -c documentation.tex
