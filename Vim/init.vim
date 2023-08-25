" Plugins ========================================================

call plug#begin('~/.local/share/nvim/site/plugged')

" Git in vim
Plug 'tpope/vim-fugitive'
" Ranger in vim
Plug 'francoiscabrol/ranger.vim'
" Better c++ file 
Plug 'octol/vim-cpp-enhanced-highlight'
" MD file colors
Plug 'preservim/vim-markdown'
	Plug 'godlygeek/tabular'
" Colors
Plug 'bluz71/vim-nightfly-guicolors'
" Replace
Plug 'tpope/vim-surround'
Plug 'vim-scripts/ReplaceWithRegister'
" Nerd tree
Plug 'preservim/nerdtree'
" Grammar check      
Plug 'vigoux/LanguageTool.nvim'

call plug#end()

" Relative numbers

set number relativenumber
set spell

" Tabs 

set tabstop=2
set shiftwidth=2
set expandtab
set autoindent

" Wrap line

set nowrap

" Search settings

set ignorecase
set smartcase

" Colors

set termguicolors
set background="dark"
set signcolumn=yes
colorscheme nightfly 

" Split
set splitright
set splitbelow

" Key binds

