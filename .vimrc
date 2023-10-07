set number
set ff=unix

function! SetCSettings()
	highlight BadWhitespace ctermbg=red guibg=red
	set tabstop=8
	set shiftwidth=8
	set autoindent
	set smartindent
	set textwidth=79
	set cindent
	syntax enable
	set number
	match BadWhitespace /\s\+$/
endfunction

function! SetPythonSettings()
	highlight BadWhitespace ctermbg=red guibg=red
	set encoding=utf-8
	set tabstop=4
	set softtabstop=4
	set shiftwidth=4
	set textwidth=79
	set expandtab
	set autoindent
	match BadWhitespace /\s\+$/
	syntax enable
endfunction


au BufNewFile,Bufread *.c call SetCSettings()
au BufNewFile,Bufread *.h call SetCSettings()
au BufNewFile,BufRead *.py call SetPythonSettings()
