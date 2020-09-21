# HTML_STYLING

# Description
1. Add basic styling to html docs (via stdin) to prepare them for turning into PDF documents.

Takes HTML output (from markdown) through stdin and adds some basic styling to it ready to pipe it into an html to pdf generator.

Usage:
markdown document.md | mdstyle | wkhtmltopdf - out.pdf
ToDo:
[] Add command line args to specify: margin, sizes, center etc [] Add command line args to point to style sheet [] Write Markdown parser & integrate

2. A basic HTML parser.
htmlParser is a basic XHTML 1.0 parsing tool that determines correctness
of the block structure in html files.

In general, if a tag formated as <tag> is detected in the file,
the parser looks for a corresponding </tag>. Everything else is ignored.
