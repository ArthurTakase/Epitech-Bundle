// Plugins
import vue from '@vitejs/plugin-vue'

// Utilities
import { defineConfig } from 'vite'
// import { fileURLToPath, URL } from 'node:url'

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [
    vue(),
  ],
  define: { 'process.env': {} },
  // resolve: {
  //   alias: {
  //     '@': fileURLToPath(new URL('./src', import.meta.url))
  //   },
  // },
  build: {
    outDir: 'dist',
    assetsDir: '',
    // sourcemap: 'inline',
    minify: true,
  },
  server: {
    host: true,
    port: 8080,
    watch: {
      usePolling: true
    },
  }
})
