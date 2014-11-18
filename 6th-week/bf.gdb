set verbose on
b main 
b execute_code
r < input-3
commands 1
watch inst
watch pcy
watch pcx
end
